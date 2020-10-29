cmake_minimum_required(VERSION 3.10)
project(tp1taller)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

include_directories(src/models)
include_directories(src/utils)

include(FindPkgConfig)

add_executable(observatory        
        
        src/models/Camera.cpp
        src/models/Camera.h
        src/models/Image.cpp
        src/models/Image.h
        src/models/Observatory.cpp
        src/models/Observatory.h
        src/models/Photo.cpp
        src/models/Photo.h
        src/models/types.h
        src/models/ObservatorySimulator.cpp
        src/models/ObservatorySimulator.h

        src/utils/Logger.cpp
        src/utils/Logger.h
        src/utils/IPC/SharedMemory.h
        src/utils/IPC/signals/EventHandler.h
        src/utils/IPC/signals/SIGINT_Handler.h
        src/utils/IPC/signals/SignalHandler.cpp
        src/utils/IPC/signals/SignalHandler.h

        src/main.cpp)
