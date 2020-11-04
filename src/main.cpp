#define CONFIG_PATH "../config"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "models/types.h"
#include "utils/Logger.h"
#include "models/ObservatorySimulator.h"
#include "utils/ErrorHandler.h"

//TODO: Move to fileManager
int readConfigFile(size_t &quantityCameras, size_t &pixelsWidthOrHeightPerPhoto);

int main(int argc, char *argv[]) {
    size_t quantityCameras, pixelsWidthOrHeightPerPhoto;
    int resultCode = readConfigFile(quantityCameras, pixelsWidthOrHeightPerPhoto);
    Logger *logger;

    if(resultCode < 0)
        return EXIT_FAILURE;

    std::cout << "El programa ha iniciado" << std::endl;
    std::cout << "Se ingresaron " << quantityCameras << " Cameras y " << pixelsWidthOrHeightPerPhoto << " Pixels" << std::endl;
    std::cout << "Simulando..." << std::endl;

    logger->getInstance()->log("El programa ha iniciado");
    resolution_t camerasResolution;

    camerasResolution.height = pixelsWidthOrHeightPerPhoto;
    camerasResolution.width = pixelsWidthOrHeightPerPhoto;
    ObservatorySimulator* simulator = new ObservatorySimulator(quantityCameras, camerasResolution);

    simulator->run();

    return EXIT_SUCCESS;
}

// TODO: Move to utils
int readConfigFile(size_t &quantityCameras, size_t &pixelsWidthOrHeightPerPhoto) {
    std::ifstream configFile(CONFIG_PATH);
    ErrorHandler *errorHandler;
    
    if (configFile.is_open()) {
        std::cout << "Se pudo abrir el archivo de configuracion" << std::endl;
        std::string line;
        try {
            std::getline(configFile, line);
            quantityCameras = std::stoi(line);

            std::getline(configFile, line);
            pixelsWidthOrHeightPerPhoto = std::stoi(line);

            return 0;
        } catch (std::exception const &ex) {
            configFile.close();
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Error al leer el archivo de configuracion ");
            return -1;
        }
        configFile.close();
    } else {
        errorHandler->getInstance()->throwError(GENERIC_ERROR, "No se encontro archivo de configuracion!");
        return -1;
    }
}
