#include "./cliregplugincontext.h"
#include "google/protobuf/util/json_util.h"
#include <chrono>
#include <string>
#include <string_view>
#include <chrono>

bool ClientRegistryPluginContext::onConfigure(size_t config_size)
{
    using namespace std::chrono;
    const WasmDataPtr configuration = getBufferBytes(WasmBufferType::PluginConfiguration, 0, config_size);
    LOG_INFO("onConfigure called!!!!!!!");
    LOG_INFO(configuration->toString());

    proxy_set_tick_period_milliseconds(2000);

    // JsonParseOptions jsonOptions;
    // const Status options_status = JsonStringToMessage(
    //     configuration->toString(),
    //     &config,
    //     jsonOptions);
    // if (options_status != Status::OK)
    // {
    //     LOG_ERROR("Cannot parse plugin configuration JSON string: " + configuration->toString());
    //     return false;
    // }
    // LOG_INFO("Loading Config: " + config.clustername());

    // // Generate the GRPC configuration
    // GrpcService grpc_service;
    // grpc_service.mutable_envoy_grpc()->set_cluster_name(config.clustername());
    // grpc_service.SerializeToString(&service);

    return true;
}

bool ClientRegistryPluginContext::onStart(size_t config_size) {
    using namespace std::chrono;
    LOG_INFO("onStart called!!!!!!!!!!");
    LOG_INFO(std::to_string(id()));
    LOG_INFO(std::string{root_id()});

    return true;
}

void ClientRegistryPluginContext::onTick() {
    LOG_INFO("TICK");
    setSharedData("tick_time", std::to_string(getCurrentTimeNanoseconds()));
}