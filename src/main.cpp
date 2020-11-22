#define CONFIG_PATH "../config"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "models/types.h"
#include "utils/Logger.h"
#include "models/ObservatorySimulator.h"
#include "utils/ErrorHandler.h"

#define ARGV_SIMULATION_MODE 1
#define ARGV_APP_MODE 2

int readConfigFile(size_t &quantityCameras, size_t &pixelsWidthOrHeightPerPhoto);

int main(int argc, char *argv[]) {
    if(!argv || !argv[ARGV_SIMULATION_MODE]) {
        cout << "No se han ingresado los parametros necesarios" << endl;
        return EXIT_FAILURE;
    }

    string appSimulatorMode;

    if(strlen(argv[ARGV_SIMULATION_MODE]) == 0) {
        cout << "No ha ingresado un modo para simular" << endl;
        return EXIT_FAILURE;
    }

    appSimulatorMode = argv[ARGV_SIMULATION_MODE];
    Logger *logger;

    if(argv[ARGV_APP_MODE] && !strcmp(argv[ARGV_APP_MODE], "DEBUG")) {
        cout << "Se va a iniciar debug" << endl;
        logger->setDebug();
    }
    
    size_t quantityCameras, pixelsWidthOrHeightPerPhoto;
    int resultCode = readConfigFile(quantityCameras, pixelsWidthOrHeightPerPhoto);

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

    if (appSimulatorMode == "SHARED_MEMORY") {
        cout << "Se va a simular shared" << endl;
        logger->getInstance()->log("El programa se ejecutara en modo shared memory");
        simulator->runSharedMem();
    }
    
    if(appSimulatorMode == "FIFOS") {
        cout << "Se va a simular fifos" << endl;
        logger->getInstance()->log("El programa se ejecutara en modo fifos");
        simulator->runFifos();
    }

    else {
        logger->getInstance()->log("No ha ingresado un modo de simulacion valido. El programa terminara");
        cout << "No ha ingresado un modo de simulacion valido" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

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
