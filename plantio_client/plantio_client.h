#pragma once                      // Inclui esse cabeçalho apenas uma vez

#include <iostream>               // std::cout (char-out) e std::endl (end-line)
#include <string.h>               // Função strcmp
#include <stdlib.h>               // Função atoi

#include "plantio_lib.h"        // Classe Plantio

namespace devtitans::plantio {  // Pacote que a classe abaixo pertence

class PlantioClient {           // Classe

    public:
        void start(int argc, char **argv);

};

} // namespace
