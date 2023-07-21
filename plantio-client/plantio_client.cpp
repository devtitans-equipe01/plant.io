#include "plantio_client.h"

// Permite usar o cout e endl diretamente ao invés de std::cout
using namespace std;

// Entra no pacote devtitans::hello
namespace devtitans::plantio {

void PlantioClient::start(int argc, char **argv) {
    cout << "Cliente Plantio!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-sm, get-smi, set-smi, get-st, get-sti, set-sti, get-am, get-ami, set-ami, get-at, get-ati, set-ati, get-al, get-ali, set-ali" << endl;
        exit(1);
    }

    Plantio plantio;             // Classe da biblioteca Plantio

    // Comandos get-led e set-led
    if (!strcmp(argv[1], "get-sm")) {
        cout << "Valor do SM: " << plantio.getSoilMoisture() << endl;
    }
    else if (!strcmp(argv[1], "get-smi")) {
        cout << "Valor do SMI: " << plantio.getSoilMoistureInterval() << endl;
    }
    else if (!strcmp(argv[1], "get-st")) {
        cout << "Valor do ST: " << plantio.getSoilTemperature() << endl;
    }
    else if (!strcmp(argv[1], "get-sti")) {
        cout << "Valor do STI: " << plantio.getSoilTemperatureInterval() << endl;
    }
    else if (!strcmp(argv[1], "get-am")) {
        cout << "Valor do AM: " << plantio.getAmbientMoisture() << endl;
    }
    else if (!strcmp(argv[1], "get-ami")) {
        cout << "Valor do AMI: " << plantio.getAmbientMoistureInterval() << endl;
    }
    else if (!strcmp(argv[1], "get-at")) {
        cout << "Valor do AT: " << plantio.getAmbientTemperature() << endl;
    }
    else if (!strcmp(argv[1], "get-ati")) {
        cout << "Valor do ATI: " << plantio.getAmbientTemperatureInterval() << endl;
    }
    else if (!strcmp(argv[1], "get-al")) {
        cout << "Valor do AL: " << plantio.getAmbientLight() << endl;
    }
    else if (!strcmp(argv[1], "get-ali")) {
        cout << "Valor do ALI: " << plantio.getAmbientLightInterval() << endl;
    }
    else if (!strcmp(argv[1], "set-smi")) {
        long smiValue = atol(argv[2]);
        if (plantio.setSoilMoistureInterval(smiValue))
            cout << "Valor do SMI setado para " << smiValue << endl;
        else
            cout << "Erro ao setar valor do SMI para " << smiValue << endl;
    }
    else if (!strcmp(argv[1], "set-sti")) {
        long stiValue = atol(argv[2]);
        if (plantio.setSoilTemperatureInterval(stiValue))
            cout << "Valor do STI setado para " << stiValue << endl;
        else
            cout << "Erro ao setar valor do STI para " << stiValue << endl;
    }
    else if (!strcmp(argv[1], "set-ami")) {
        long amiValue = atol(argv[2]);
        if (plantio.setAmbientMoistureInterval(amiValue))
            cout << "Valor do AMI setado para " << amiValue << endl;
        else
            cout << "Erro ao setar valor do AMI para " << amiValue << endl;
    }
    else if (!strcmp(argv[1], "set-ati")) {
        long atiValue = atol(argv[2]);
        if (plantio.setAmbientTemperatureInterval(atiValue))
            cout << "Valor do ATI setado para " << atiValue << endl;
        else
            cout << "Erro ao setar valor do ATI para " << atiValue << endl;
    }
    else if (!strcmp(argv[1], "set-ali")) {
        long aliValue = atol(argv[2]);
        if (plantio.setAmbientLightInterval(aliValue))
            cout << "Valor do ALI setado para " << aliValue << endl;
        else
            cout << "Erro ao setar valor do ALI para " << aliValue << endl;
    }
    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace

// Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp
using namespace devtitans::plantio; 

int main(int argc, char **argv) {
    PlantioClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}