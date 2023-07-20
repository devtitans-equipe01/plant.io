#include "plantio_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::plantio {      // Entra no pacote devtitans::hello

void PlantioClient::start(int argc, char **argv) {
    cout << "Cliente Plantio!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: getSoilMoisture, getSoilMoistureInterval, setSoilMoistureInterval, getSoilTemperature, getSoilTemperatureInterval, setSoilTemperatureInterval" << endl;
        exit(1);
    }

    Plantio plantio;             // Classe da biblioteca Plantio

    // Comandos getSoilTemperature, getSoilTemperatureInterval e setSoilTemperatureInterval
    if (!strcmp(argv[1], "get-soil-moisture")) {
        cout << "Valor do Sensor de Umidade do Solo: " << plantio.getSoilMoisture() << endl;
    }

    else if (!strcmp(argv[1], "get-soil-moisture-interval")) {
            cout << "Valor do Intervalo do Sensor de Umidade do Solo " << plantio.getSoilMoistureInterval() << endl;
    }

    else if (!strcmp(argv[1], "set-soil-moisture-interval")) {
        int smi_value = atol(argv[2]);
        if (plantio.setSoilMoistureInterval(smi_value))
            cout << "Valor do Intervalo do Sensor de Umidade do Solo setado para " << smi_value << endl;
        else
            cout << "Erro ao setar valor do Led para " << smi_value << endl;
    }

    // Comandos getSoilMoisture, getSoilMoistureInterval e setSoilMoistureInterval
    else if (!strcmp(argv[1], "get-soil-temperature")) {
        cout << "Valor do Sensor de Umidade do Solo: " << plantio.getSoilTemperature() << endl;
    }

    else if (!strcmp(argv[1], "get-soil-temperature-interval")) {
            cout << "Valor do Intervalo do Sensor de Umidade do Solo " << plantio.getSoilTemperatureInterval() << endl;
    }

    else if (!strcmp(argv[1], "set-soil-temperature-interval")) {
        int sti_value = atol(argv[2]);
        if (plantio.setSoilTemperatureInterval(sti_value))
            cout << "Valor do Intervalo do Sensor de Umidade do Solo setado para " << sti_value << endl;
        else
            cout << "Erro ao setar valor do Sensor de Umidade do Solo para " << sti_value << endl;
    }

    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::plantio; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    PlantioClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}
