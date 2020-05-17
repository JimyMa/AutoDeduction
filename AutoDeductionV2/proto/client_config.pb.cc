// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: client_config.proto

#include "client_config.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace client_config {
class ClientConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ClientConfig> _instance;
} _ClientConfig_default_instance_;
}  // namespace client_config
static void InitDefaultsscc_info_ClientConfig_client_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::client_config::_ClientConfig_default_instance_;
    new (ptr) ::client_config::ClientConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::client_config::ClientConfig::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ClientConfig_client_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ClientConfig_client_5fconfig_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_client_5fconfig_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_client_5fconfig_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_client_5fconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_client_5fconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::client_config::ClientConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::client_config::ClientConfig, servercert_path_),
  PROTOBUF_FIELD_OFFSET(::client_config::ClientConfig, clientcert_path_),
  PROTOBUF_FIELD_OFFSET(::client_config::ClientConfig, clientkey_path_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::client_config::ClientConfig)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::client_config::_ClientConfig_default_instance_),
};

const char descriptor_table_protodef_client_5fconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023client_config.proto\022\rclient_config\"X\n\014"
  "ClientConfig\022\027\n\017servercert_path\030\001 \001(\t\022\027\n"
  "\017clientcert_path\030\002 \001(\t\022\026\n\016clientkey_path"
  "\030\003 \001(\tb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_client_5fconfig_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_client_5fconfig_2eproto_sccs[1] = {
  &scc_info_ClientConfig_client_5fconfig_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_client_5fconfig_2eproto_once;
static bool descriptor_table_client_5fconfig_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_client_5fconfig_2eproto = {
  &descriptor_table_client_5fconfig_2eproto_initialized, descriptor_table_protodef_client_5fconfig_2eproto, "client_config.proto", 134,
  &descriptor_table_client_5fconfig_2eproto_once, descriptor_table_client_5fconfig_2eproto_sccs, descriptor_table_client_5fconfig_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_client_5fconfig_2eproto::offsets,
  file_level_metadata_client_5fconfig_2eproto, 1, file_level_enum_descriptors_client_5fconfig_2eproto, file_level_service_descriptors_client_5fconfig_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_client_5fconfig_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_client_5fconfig_2eproto), true);
namespace client_config {

// ===================================================================

void ClientConfig::InitAsDefaultInstance() {
}
class ClientConfig::_Internal {
 public:
};

ClientConfig::ClientConfig()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:client_config.ClientConfig)
}
ClientConfig::ClientConfig(const ClientConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  servercert_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_servercert_path().empty()) {
    servercert_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servercert_path_);
  }
  clientcert_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_clientcert_path().empty()) {
    clientcert_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.clientcert_path_);
  }
  clientkey_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_clientkey_path().empty()) {
    clientkey_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.clientkey_path_);
  }
  // @@protoc_insertion_point(copy_constructor:client_config.ClientConfig)
}

void ClientConfig::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ClientConfig_client_5fconfig_2eproto.base);
  servercert_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientcert_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientkey_path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ClientConfig::~ClientConfig() {
  // @@protoc_insertion_point(destructor:client_config.ClientConfig)
  SharedDtor();
}

void ClientConfig::SharedDtor() {
  servercert_path_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientcert_path_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientkey_path_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ClientConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ClientConfig& ClientConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ClientConfig_client_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void ClientConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:client_config.ClientConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  servercert_path_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientcert_path_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientkey_path_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* ClientConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string servercert_path = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_servercert_path();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "client_config.ClientConfig.servercert_path"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string clientcert_path = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_clientcert_path();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "client_config.ClientConfig.clientcert_path"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string clientkey_path = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_clientkey_path();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "client_config.ClientConfig.clientkey_path"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ClientConfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:client_config.ClientConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string servercert_path = 1;
  if (this->servercert_path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_servercert_path().data(), static_cast<int>(this->_internal_servercert_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "client_config.ClientConfig.servercert_path");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_servercert_path(), target);
  }

  // string clientcert_path = 2;
  if (this->clientcert_path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_clientcert_path().data(), static_cast<int>(this->_internal_clientcert_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "client_config.ClientConfig.clientcert_path");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_clientcert_path(), target);
  }

  // string clientkey_path = 3;
  if (this->clientkey_path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_clientkey_path().data(), static_cast<int>(this->_internal_clientkey_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "client_config.ClientConfig.clientkey_path");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_clientkey_path(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:client_config.ClientConfig)
  return target;
}

size_t ClientConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:client_config.ClientConfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string servercert_path = 1;
  if (this->servercert_path().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_servercert_path());
  }

  // string clientcert_path = 2;
  if (this->clientcert_path().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_clientcert_path());
  }

  // string clientkey_path = 3;
  if (this->clientkey_path().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_clientkey_path());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ClientConfig::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:client_config.ClientConfig)
  GOOGLE_DCHECK_NE(&from, this);
  const ClientConfig* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ClientConfig>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:client_config.ClientConfig)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:client_config.ClientConfig)
    MergeFrom(*source);
  }
}

void ClientConfig::MergeFrom(const ClientConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:client_config.ClientConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.servercert_path().size() > 0) {

    servercert_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servercert_path_);
  }
  if (from.clientcert_path().size() > 0) {

    clientcert_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.clientcert_path_);
  }
  if (from.clientkey_path().size() > 0) {

    clientkey_path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.clientkey_path_);
  }
}

void ClientConfig::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:client_config.ClientConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClientConfig::CopyFrom(const ClientConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:client_config.ClientConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientConfig::IsInitialized() const {
  return true;
}

void ClientConfig::InternalSwap(ClientConfig* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  servercert_path_.Swap(&other->servercert_path_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  clientcert_path_.Swap(&other->clientcert_path_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  clientkey_path_.Swap(&other->clientkey_path_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata ClientConfig::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace client_config
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::client_config::ClientConfig* Arena::CreateMaybeMessage< ::client_config::ClientConfig >(Arena* arena) {
  return Arena::CreateInternal< ::client_config::ClientConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>