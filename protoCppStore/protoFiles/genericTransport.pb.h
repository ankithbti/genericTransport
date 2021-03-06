// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protoFiles/genericTransport.proto

#ifndef PROTOBUF_protoFiles_2fgenericTransport_2eproto__INCLUDED
#define PROTOBUF_protoFiles_2fgenericTransport_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace genericTransport {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_protoFiles_2fgenericTransport_2eproto();
void protobuf_AssignDesc_protoFiles_2fgenericTransport_2eproto();
void protobuf_ShutdownFile_protoFiles_2fgenericTransport_2eproto();

class HeartBeat;

// ===================================================================

class HeartBeat : public ::google::protobuf::Message {
 public:
  HeartBeat();
  virtual ~HeartBeat();

  HeartBeat(const HeartBeat& from);

  inline HeartBeat& operator=(const HeartBeat& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HeartBeat& default_instance();

  void Swap(HeartBeat* other);

  // implements Message ----------------------------------------------

  inline HeartBeat* New() const { return New(NULL); }

  HeartBeat* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HeartBeat& from);
  void MergeFrom(const HeartBeat& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HeartBeat* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string hbText = 1;
  bool has_hbtext() const;
  void clear_hbtext();
  static const int kHbTextFieldNumber = 1;
  const ::std::string& hbtext() const;
  void set_hbtext(const ::std::string& value);
  void set_hbtext(const char* value);
  void set_hbtext(const char* value, size_t size);
  ::std::string* mutable_hbtext();
  ::std::string* release_hbtext();
  void set_allocated_hbtext(::std::string* hbtext);

  // @@protoc_insertion_point(class_scope:genericTransport.HeartBeat)
 private:
  inline void set_has_hbtext();
  inline void clear_has_hbtext();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr hbtext_;
  friend void  protobuf_AddDesc_protoFiles_2fgenericTransport_2eproto();
  friend void protobuf_AssignDesc_protoFiles_2fgenericTransport_2eproto();
  friend void protobuf_ShutdownFile_protoFiles_2fgenericTransport_2eproto();

  void InitAsDefaultInstance();
  static HeartBeat* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// HeartBeat

// required string hbText = 1;
inline bool HeartBeat::has_hbtext() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void HeartBeat::set_has_hbtext() {
  _has_bits_[0] |= 0x00000001u;
}
inline void HeartBeat::clear_has_hbtext() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void HeartBeat::clear_hbtext() {
  hbtext_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_hbtext();
}
inline const ::std::string& HeartBeat::hbtext() const {
  // @@protoc_insertion_point(field_get:genericTransport.HeartBeat.hbText)
  return hbtext_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HeartBeat::set_hbtext(const ::std::string& value) {
  set_has_hbtext();
  hbtext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:genericTransport.HeartBeat.hbText)
}
inline void HeartBeat::set_hbtext(const char* value) {
  set_has_hbtext();
  hbtext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:genericTransport.HeartBeat.hbText)
}
inline void HeartBeat::set_hbtext(const char* value, size_t size) {
  set_has_hbtext();
  hbtext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:genericTransport.HeartBeat.hbText)
}
inline ::std::string* HeartBeat::mutable_hbtext() {
  set_has_hbtext();
  // @@protoc_insertion_point(field_mutable:genericTransport.HeartBeat.hbText)
  return hbtext_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HeartBeat::release_hbtext() {
  clear_has_hbtext();
  return hbtext_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HeartBeat::set_allocated_hbtext(::std::string* hbtext) {
  if (hbtext != NULL) {
    set_has_hbtext();
  } else {
    clear_has_hbtext();
  }
  hbtext_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), hbtext);
  // @@protoc_insertion_point(field_set_allocated:genericTransport.HeartBeat.hbText)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace genericTransport

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_protoFiles_2fgenericTransport_2eproto__INCLUDED
