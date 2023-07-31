#include <android/binder_manager.h>
#include <aidl/devtitans/plantio/IPlantio.h>
#include <iostream> // std::cout e std::endl (end-line)

using namespace aidl::devtitans::plantio; // IPlantio
using namespace std;                      // std::shared_ptr
using namespace ndk;                      // ndk::SpAIBinder

int main()
{
    shared_ptr<IPlantio> plantioService;
    plantioService = IPlantio::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.plantio.IPlantio/default")));

    if (!plantioService)
    {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_getSoilMoisture_return;
    ScopedAStatus getSoilMoistureStatus = plantioService->getSoilMoisture(&_aidl_getSoilMoisture_return);
    int soilMoisture = static_cast<int32_t>(_aidl_getSoilMoisture_return);
    cout << "Soil Moisture: " << soilMoisture << endl;

    int32_t _aidl_getSoilMoistureInterval_return;
    ScopedAStatus getSoilMoistureIntervalStatus = plantioService->getSoilMoistureInterval(&_aidl_getSoilMoistureInterval_return);
    int soilMoistureInterval = static_cast<int32_t>(_aidl_getSoilMoistureInterval_return);
    cout << "Soil Moisture Interval: " << soilMoisture << endl;

    int32_t _aidl_getSoilTemperature_return;
    ScopedAStatus getSoilTemperatureStatus = plantioService->getSoilTemperature(&_aidl_getSoilTemperature_return);
    int soilTemperature = static_cast<int32_t>(_aidl_getSoilTemperature_return);
    cout << "Soil Temperature: " << soilTemperature << endl;

    int32_t _aidl_getSoilTemperatureInterval_return;
    ScopedAStatus getSoilTemperatureIntervalStatus = plantioService->getSoilTemperatureInterval(&_aidl_getSoilTemperatureInterval_return);
    int soilTemperatureInterval = static_cast<int32_t>(_aidl_getSoilTemperatureInterval_return);
    cout << "Soil Temperature Interval: " << soilTemperatureInterval << endl;

    int32_t _aidl_getAmbientMoisture_return;
    ScopedAStatus getAmbientMoistureStatus = plantioService->getAmbientMoisture(&_aidl_getAmbientMoisture_return);
    int ambientMoisture = static_cast<int32_t>(_aidl_getAmbientMoisture_return);
    cout << "Ambient Moisture: " << ambientMoisture << endl;

    int32_t _aidl_getAmbientMoistureInterval_return;
    ScopedAStatus getAmbientMoistureIntervalStatus = plantioService->getAmbientMoistureInterval(&_aidl_getAmbientMoistureInterval_return);
    int ambientMoistureInterval = static_cast<int32_t>(_aidl_getAmbientMoistureInterval_return);
    cout << "Ambient Moisture Interval: " << ambientMoistureInterval << endl;

    int32_t _aidl_getAmbientTemperature_return;
    ScopedAStatus getAmbientTemperatureStatus = plantioService->getAmbientTemperature(&_aidl_getAmbientTemperature_return);
    int ambientTemperature = static_cast<int32_t>(_aidl_getAmbientTemperature_return);
    cout << "Ambient Temperature: " << ambientTemperature << endl;

    int32_t _aidl_getAmbientTemperatureInterval_return;
    ScopedAStatus getAmbientTemperatureIntervalStatus = plantioService->getAmbientTemperatureInterval(&_aidl_getAmbientTemperatureInterval_return);
    int ambientTemperatureInterval = static_cast<int32_t>(_aidl_getAmbientTemperatureInterval_return);
    cout << "Ambient Temperature Interval: " << ambientTemperatureInterval << endl;

    int32_t _aidl_getAmbientLight_return;
    ScopedAStatus getAmbientLightStatus = plantioService->getAmbientLight(&_aidl_getAmbientLight_return);
    int ambientLight = static_cast<int32_t>(_aidl_getAmbientLight_return);
    cout << "Ambient Light: " << ambientLight << endl;

    int32_t _aidl_getAmbientLightInterval_return;
    ScopedAStatus getAmbientLightIntervalStatus = plantioService->getAmbientLightInterval(&_aidl_getAmbientLightInterval_return);
    int ambientLightInterval = static_cast<int32_t>(_aidl_getAmbientLightInterval_return);
    cout << "Ambient Light Interval: " << ambientLightInterval << endl;

    return 0;
}