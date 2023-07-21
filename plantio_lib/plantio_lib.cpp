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

float Plantio::readFileValue(string file) {
    int connected = this->connect();

    // Conectado. Vamos solicitar o valor ao dispositivo
    if (connected == 1) {
        float value;
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
    return -1.0;
}

bool Plantio::writeFileValue(string file, long value) {
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

float Plantio::getSoilMoisture() {
  return this->readFileValue("sm");
}

long Plantio::getSoilMoistureInterval() {
  return (long)this->readFileValue("smi");
}

bool Plantio::setSoilMoistureInterval(long milliseconds) {
  return this->writeFileValue("smi", milliseconds);
}

float Plantio::getSoilTemperature() {
  return this->readFileValue("st");
}

long Plantio::getSoilTemperatureInterval() {
  return (long)this->readFileValue("sti");
}

bool Plantio::setSoilTemperatureInterval(long milliseconds) {
  return this->writeFileValue("sti", milliseconds);
}

float Plantio::getAmbientMoisture() {
  return this->readFileValue("am");
}

long Plantio::getAmbientMoistureInterval() {
  return (long)this->readFileValue("ami");
}

bool Plantio::setAmbientMoistureInterval(long milliseconds) {
  return this->writeFileValue("ami", milliseconds);
}

float Plantio::getAmbientTemperature() {
return this->readFileValue("at");
}

long Plantio::getAmbientTemperatureInterval() {
  return (long)this->readFileValue("ati");
}

bool Plantio::setAmbientTemperatureInterval(long milliseconds) {
  return this->writeFileValue("ati", milliseconds);
}

float Plantio::getAmbientLight() {
  return this->readFileValue("al");
}

long Plantio::getAmbientLightInterval() {
  return (long)this->readFileValue("ali");
}

bool Plantio::setAmbientLightInterval(long milliseconds) {
  return this->writeFileValue("ali", milliseconds);
}

} // namespace