#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/plantio/BnPlantio.h> // Criado pelo AIDL automaticamente

#include "plantio_lib.h" // Classe Plantio (biblioteca)

using namespace devtitans::plantio;

namespace aidl::devtitans::plantio
{

    class PlantioService : public BnPlantio
    {
    public:
        ndk::ScopedAStatus connect(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getSoilMoisture(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getSoilMoistureInterval(int32_t *_aidl_return) override;
        ndk::ScopedAStatus setSoilMoistureInterval(int32_t in_milliseconds, bool *_aidl_return) override;
        ndk::ScopedAStatus getSoilTemperature(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getSoilTemperatureInterval(int32_t *_aidl_return) override;
        ndk::ScopedAStatus setSoilTemperatureInterval(int32_t in_milliseconds, bool *_aidl_return) override;
        ndk::ScopedAStatus getAmbientMoisture(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getAmbientMoistureInterval(int32_t *_aidl_return) override;
        ndk::ScopedAStatus setAmbientMoistureInterval(int32_t in_milliseconds, bool *_aidl_return) override;
        ndk::ScopedAStatus getAmbientTemperature(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getAmbientTemperatureInterval(int32_t *_aidl_return) override;
        ndk::ScopedAStatus setAmbientTemperatureInterval(int32_t in_milliseconds, bool *_aidl_return) override;
        ndk::ScopedAStatus getAmbientLight(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getAmbientLightInterval(int32_t *_aidl_return) override;
        ndk::ScopedAStatus setAmbientLightInterval(int32_t in_milliseconds, bool *_aidl_return) override;

    private:
        Plantio plantio; // Biblioteca
    };

}