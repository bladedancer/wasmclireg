#ifndef __CLIREGPLUGINCONTEXT_H__
#define __CLIREGPLUGINCONTEXT_H__
#include <string>
#include <string_view>
#include <unordered_map>

#include "proxy_wasm_intrinsics.h"

class ClientRegistryPluginContext : public RootContext {
public:
  explicit ClientRegistryPluginContext(uint32_t id, std::string_view root_id) : RootContext(id, root_id) {}

  bool onConfigure(size_t) override;
  bool onStart(size_t) override;
  void onTick() override;

private:
  std::string service;
};

static RegisterContextFactory register_ClientRegistryPluginContext(ROOT_FACTORY(ClientRegistryPluginContext),"cliregPlugin");
#endif