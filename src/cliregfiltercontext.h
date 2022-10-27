#ifndef __CLIREGFILTERCONTEXT_H__
#define __CLIREGFILTERCONTEXT_H__
#include <string>
#include <string_view>
#include "proxy_wasm_intrinsics.h"

#include "google/protobuf/util/json_util.h"


class ClientRegistryFilterContext : public Context
{
public:
  explicit ClientRegistryFilterContext(uint32_t id, RootContext *root);
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
};

static RegisterContextFactory register_ClientRegistryFilterContext(CONTEXT_FACTORY(ClientRegistryFilterContext), "cliregFilter");
#endif