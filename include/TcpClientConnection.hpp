/* 
 * File:   TcpClientConnection.hpp
 * Author: ankithbti
 *
 * Created on 29 November, 2015, 9:28 PM
 */

#ifndef TCPCLIENTCONNECTION_HPP
#define	TCPCLIENTCONNECTION_HPP


#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <Common.hpp>
#include <vector>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

namespace genericTransport
{

template <typename SchemaAdaptor>
class TcpConnectionManager;

template<typename SchemaAdaptor>
class TcpClientConnection : private boost::noncopyable, public boost::enable_shared_from_this<TcpClientConnection<SchemaAdaptor> >
{
public:
    typedef boost::shared_ptr<TcpClientConnection<SchemaAdaptor> > SmartPtr;

private:

    SocketSmartPtr _socket;

    ArrayBuffer _buffer;
    std::string _clientId;
    boost::shared_ptr<SchemaAdaptor> _schemaAdaptor;

    boost::shared_ptr<TcpConnectionManager<SchemaAdaptor> > _manager;

    /// Perform an asynchronous read operation.

    void do_read()
    {
        _socket->async_read_some(boost::asio::buffer(_buffer), boost::bind(&TcpClientConnection::asyncRead, this->shared_from_this(), _1, _2));
    }

    void asyncRead(boost::system::error_code ec, std::size_t bytes_transferred)
    {
        std::cout << " Read " << bytes_transferred << " bytes sent from client - " << _buffer.data() << std::endl;
        // Use Schema Adaptor to read the bytes
        //        switch(_schemaAdaptor.decode(_buffer, bytes_transferred)){
        //        case PACKET_READ_OK:
        //        SA will only send whatever it wants
        //            break;
        //        case PACKET_READ_INCOMPLETE:
        //          do_read();
        //            break;
        //        case PACKET_READ_ERROR:
        //            break;
        //        default:
        //            break;
        //        }         

    }

    /// Perform an asynchronous write operation.

    void asyncWrite(boost::system::error_code ec, std::size_t bytes_transferred)
    {
        if (!ec)
        {
            // Initiate graceful connection closure.
            boost::system::error_code ignored_ec;
            _socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both,
                              ignored_ec);
        }

        if (ec != boost::asio::error::operation_aborted)
        {
            _manager->stop(this->shared_from_this());
        }
    }


public:

    TcpClientConnection(SocketSmartPtr socket, boost::shared_ptr<TcpConnectionManager<SchemaAdaptor> > manager) :
    _socket(socket),
    _manager(manager)
    {
        std::cout << " Creating SA " << std::endl;
        _schemaAdaptor = boost::shared_ptr<SchemaAdaptor>(new SchemaAdaptor());
        std::cout << " Created SA " << std::endl;
    }

    void do_write(ArrayBuffer& buffers)
    {
        //        std::vector<boost::asio::const_buffer> buffers;
        //        buffers.push_back(boost::asio::buffer("TestReply"));
        boost::asio::async_write(*(_socket.get()), buffers, boost::bind(&TcpClientConnection<SchemaAdaptor>::asyncWrite, this->shared_from_this(), _1, _2));
    }

    void start()
    {
        std::cout << " Starting Client Connection. " << std::endl;
        do_read();
    }

    void stop()
    {
        _socket->close();
        _socket.reset();
    }

    ~TcpClientConnection()
    {
        if (_socket)
        {
            if (_socket->is_open())
            {
                _socket->close();
            }
            _socket.reset();
        }
    }

};


}

#endif	/* TCPCLIENTCONNECTION_HPP */

