#include "plantio_service.h"

namespace aidl::devtitans::plantio
{
    ndk::ScopedAStatus PlantioService::connect(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getSoilMoisture(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getSoilMoisture();
        LOG(INFO) << "getSoilMoisture(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getSoilMoistureInterval(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getSoilMoistureInterval();
        LOG(INFO) << "getSoilMoistureInterval(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::setSoilMoistureInterval(int32_t in_milliseconds, bool *_aidl_return)
    {
        *_aidl_return = this->plantio.setSoilMoistureInterval(in_milliseconds);
        LOG(INFO) << "setSoilMoistureInterval( " << in_milliseconds << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getSoilTemperature(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getSoilTemperature();
        LOG(INFO) << "getSoilTemperature(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getSoilTemperatureInterval(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getSoilTemperatureInterval();
        LOG(INFO) << "getSoilTemperatureInterval(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::setSoilTemperatureInterval(int32_t in_milliseconds, bool *_aidl_return)
    {
        *_aidl_return = this->plantio.setSoilTemperatureInterval(in_milliseconds);
        LOG(INFO) << "setSoilTemperatureInterval( " << in_milliseconds << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientMoisture(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientMoisture();
        LOG(INFO) << "getAmbientMoisture(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientMoistureInterval(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientMoistureInterval();
        LOG(INFO) << "getAmbientMoistureInterval(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::setAmbientMoistureInterval(int32_t in_milliseconds, bool *_aidl_return)
    {
        *_aidl_return = this->plantio.setAmbientMoistureInterval(in_milliseconds);
        LOG(INFO) << "setAmbientMoistureInterval( " << in_milliseconds << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientTemperature(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientTemperature();
        LOG(INFO) << "getAmbientTemperature(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientTemperatureInterval(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientTemperatureInterval();
        LOG(INFO) << "getAmbientTemperatureInterval(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::setAmbientTemperatureInterval(int32_t in_milliseconds, bool *_aidl_return)
    {
        *_aidl_return = this->plantio.setAmbientTemperatureInterval(in_milliseconds);
        LOG(INFO) << "setAmbientTemperatureInterval( " << in_milliseconds << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientLight(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientLight();
        LOG(INFO) << "getAmbientLight(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::getAmbientLightInterval(int32_t *_aidl_return)
    {
        *_aidl_return = this->plantio.getAmbientLightInterval();
        LOG(INFO) << "getAmbientLightInterval(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus PlantioService::setAmbientLightInterval(int32_t in_milliseconds, bool *_aidl_return)
    {
        *_aidl_return = this->plantio.setAmbientLightInterval(in_milliseconds);
        LOG(INFO) << "setAmbientLightInterval( " << in_milliseconds << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }
}