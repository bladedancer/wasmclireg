#include "./cliregfiltercontext.h"

ClientRegistryFilterContext::ClientRegistryFilterContext(uint32_t id, RootContext *root) : Context(id, root) {
  LOG_INFO("FILTER_CREATED!!!!!!!!!!!!!!!!!");
  LOG_INFO(std::to_string(id));
}

FilterHeadersStatus ClientRegistryFilterContext::onRequestHeaders(uint32_t, bool end_of_stream)
{
  // Extract the client id from the payload.

  // Identify the operation

  // Compare it against the client Registry
  LOG_INFO(std::string("onRequestHeaders called ") + std::to_string(id()));
  WasmDataPtr value; 
  WasmResult result = getSharedData("tick_time", &value);

  LOG_INFO(toString(result));

  if (result == WasmResult::Ok) {
    LOG_INFO("TICK VALUE: " + value->toString());
  }

  return FilterHeadersStatus::Continue;
}
