#include "plantio_service.h"

using namespace aidl::devtitans::plantio; // PlantioService (plantio_service.cpp)
using namespace std;                      // std::shared_ptr
using namespace ndk;                      // ndk::SharedRefBase

int main()
{
    LOG(INFO) << "Iniciando Plantio AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<PlantioService> plantio_service = SharedRefBase::make<PlantioService>();

    const string instance = std::string() + IPlantio::descriptor + "/default"; // devtitans.plantio.IPlantio/default
    binder_status_t status = AServiceManager_addService(plantio_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "Plantio AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE; // Não deve chegar nunca aqui
}