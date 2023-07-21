#include "plantio_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base;                         // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devtitans::plantio {                       // Entra no pacote devtitans::plantio

int Plantio::connect() {
    char dirPath[] = "/sys/kernel/plantio";
    struct stat dirStat;
    // Se o diretório existir, retorna 1, caso contrário retorna 0
    if (stat(dirPath, &dirStat) == 0)
        if (S_ISDIR(dirStat.st_mode))
            return 1;
        else return 0;
    else return 0;
}

int Plantio::readFileValue(string file) {
    int connected = this->connect();

    // Conectado. Vamos solicitar o valor ao dispositivo
    if (connected == 1) {
        int value;
        string filename = string("/sys/kernel/plantio/") + file;
        // Abre o arquivo do módulo do kernel
        ifstream file(filename);

        // Verifica se o arquivo foi aberto com sucesso
        if (file.is_open()) {
            // Lê um inteiro do arquivo
            file >> value;
            file.close();
            return value;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return -1;
}

bool Plantio::writeFileValue(string file, int value) {
    int connected = this->connect();

    // Conectado. Vamos solicitar o valor ao dispositivo
    if (connected == 1) {
        string filename = string("/sys/kernel/plantio/") + file;
        // Abre o arquivo limpando o seu conteúdo
        ofstream file(filename, ios::trunc);

        // Verifica se o arquivo foi aberto com sucesso
        if (file.is_open()) {
            // Escreve o smValue no arquivo
            file << value;
            file.close();
            return true;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return false;
}

int Plantio::getSoilMoisture() {
  return this->readFileValue("sm");
}

int Plantio::getSoilMoistureInterval() {
  return this->readFileValue("smi");
}

bool Plantio::setSoilMoistureInterval(int milliseconds) {
  return this->writeFileValue("smi", milliseconds);
}

int Plantio::getSoilTemperature() {
  return this->readFileValue("st");
}

int Plantio::getSoilTemperatureInterval() {
  return this->readFileValue("sti");
}

bool Plantio::setSoilTemperatureInterval(int milliseconds) {
  return this->writeFileValue("sti", milliseconds);
}

int Plantio::getAmbientMoisture() {
  return this->readFileValue("am");
}

int Plantio::getAmbientMoistureInterval() {
  return this->readFileValue("ami");
}

bool Plantio::setAmbientMoistureInterval(int milliseconds) {
  return this->writeFileValue("ami", milliseconds);
}

int Plantio::getAmbientTemperature() {
return this->readFileValue("at");
}

int Plantio::getAmbientTemperatureInterval() {
  return this->readFileValue("ati");
}

bool Plantio::setAmbientTemperatureInterval(int milliseconds) {
  return this->writeFileValue("ati", milliseconds);
}

int Plantio::getAmbientLight() {
  return this->readFileValue("al");
}

int Plantio::getAmbientLightInterval() {
  return this->readFileValue("ali");
}

bool Plantio::setAmbientLightInterval(int milliseconds) {
  return this->writeFileValue("ali", milliseconds);
}

} // namespace