#define CONFIG_PATH "../config"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "models/types.h"
#include "utils/Logger.h"
#include "models/ObservatorySimulator.h"

//TODO: Move to fileManager
status_t readConfigFile(size_t &quantityCameras, size_t &pixelsWidthOrHeightPerPhoto);

int main(int argc, char *argv[]) {
    size_t quantityCameras, pixelsWidthOrHeightPerPhoto;
    status_t status = readConfigFile(quantityCameras, pixelsWidthOrHeightPerPhoto);
    Logger *logger;

    if(status.code != OK) {
        std::cout << status.errorMsg << std::endl;
        return EXIT_FAILURE;
    }

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


// TODO: Move this
status_t handleError(statusCode_t statusCode, std::string errorMsg){
    std::cerr << errorMsg << std::endl;

    status_t auxStatus;

    auxStatus.errorMsg = errorMsg;
    auxStatus.code = statusCode;

    return auxStatus;
}

status_t readConfigFile(size_t &quantityCameras, size_t &pixelsWidthOrHeightPerPhoto) {
    std::ifstream configFile(CONFIG_PATH);
    
    if (configFile.is_open()) {
        std::cout << "Se pudo abrir" << std::endl;
        std::string line;
        try {
            std::getline(configFile, line);
            quantityCameras = std::stoi(line);

            std::getline(configFile, line);
            pixelsWidthOrHeightPerPhoto = std::stoi(line);

            status_t status;

            status.code = OK;

            return status;
        } catch (std::exception const &ex) {
            configFile.close();
            return handleError(GENERIC_ERROR, "Error al leer el archivo de configuracion ");
        }
        configFile.close();
    } else {
        return handleError(GENERIC_ERROR, "No se encontro archivo de configuracion!");
    }
}
