# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/619/bin/cmake

# The command to remove a file.
RM = /snap/cmake/619/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build"

# Include any dependencies generated for this target.
include CMakeFiles/observatory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/observatory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/observatory.dir/flags.make

CMakeFiles/observatory.dir/src/models/Camera.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/models/Camera.cpp.o: ../src/models/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/observatory.dir/src/models/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/models/Camera.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Camera.cpp"

CMakeFiles/observatory.dir/src/models/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/models/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Camera.cpp" > CMakeFiles/observatory.dir/src/models/Camera.cpp.i

CMakeFiles/observatory.dir/src/models/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/models/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Camera.cpp" -o CMakeFiles/observatory.dir/src/models/Camera.cpp.s

CMakeFiles/observatory.dir/src/models/Image.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/models/Image.cpp.o: ../src/models/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/observatory.dir/src/models/Image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/models/Image.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Image.cpp"

CMakeFiles/observatory.dir/src/models/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/models/Image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Image.cpp" > CMakeFiles/observatory.dir/src/models/Image.cpp.i

CMakeFiles/observatory.dir/src/models/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/models/Image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Image.cpp" -o CMakeFiles/observatory.dir/src/models/Image.cpp.s

CMakeFiles/observatory.dir/src/models/Observatory.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/models/Observatory.cpp.o: ../src/models/Observatory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/observatory.dir/src/models/Observatory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/models/Observatory.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Observatory.cpp"

CMakeFiles/observatory.dir/src/models/Observatory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/models/Observatory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Observatory.cpp" > CMakeFiles/observatory.dir/src/models/Observatory.cpp.i

CMakeFiles/observatory.dir/src/models/Observatory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/models/Observatory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Observatory.cpp" -o CMakeFiles/observatory.dir/src/models/Observatory.cpp.s

CMakeFiles/observatory.dir/src/models/Photo.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/models/Photo.cpp.o: ../src/models/Photo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/observatory.dir/src/models/Photo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/models/Photo.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Photo.cpp"

CMakeFiles/observatory.dir/src/models/Photo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/models/Photo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Photo.cpp" > CMakeFiles/observatory.dir/src/models/Photo.cpp.i

CMakeFiles/observatory.dir/src/models/Photo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/models/Photo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/Photo.cpp" -o CMakeFiles/observatory.dir/src/models/Photo.cpp.s

CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o: ../src/models/ObservatorySimulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/ObservatorySimulator.cpp"

CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/ObservatorySimulator.cpp" > CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.i

CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/models/ObservatorySimulator.cpp" -o CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.s

CMakeFiles/observatory.dir/src/utils/Logger.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/utils/Logger.cpp.o: ../src/utils/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/observatory.dir/src/utils/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/utils/Logger.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/Logger.cpp"

CMakeFiles/observatory.dir/src/utils/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/utils/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/Logger.cpp" > CMakeFiles/observatory.dir/src/utils/Logger.cpp.i

CMakeFiles/observatory.dir/src/utils/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/utils/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/Logger.cpp" -o CMakeFiles/observatory.dir/src/utils/Logger.cpp.s

CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o: ../src/utils/IPC/signals/SignalHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/IPC/signals/SignalHandler.cpp"

CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/IPC/signals/SignalHandler.cpp" > CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.i

CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/utils/IPC/signals/SignalHandler.cpp" -o CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.s

CMakeFiles/observatory.dir/src/main.cpp.o: CMakeFiles/observatory.dir/flags.make
CMakeFiles/observatory.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/observatory.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observatory.dir/src/main.cpp.o -c "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/main.cpp"

CMakeFiles/observatory.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observatory.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/main.cpp" > CMakeFiles/observatory.dir/src/main.cpp.i

CMakeFiles/observatory.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observatory.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/src/main.cpp" -o CMakeFiles/observatory.dir/src/main.cpp.s

# Object files for target observatory
observatory_OBJECTS = \
"CMakeFiles/observatory.dir/src/models/Camera.cpp.o" \
"CMakeFiles/observatory.dir/src/models/Image.cpp.o" \
"CMakeFiles/observatory.dir/src/models/Observatory.cpp.o" \
"CMakeFiles/observatory.dir/src/models/Photo.cpp.o" \
"CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o" \
"CMakeFiles/observatory.dir/src/utils/Logger.cpp.o" \
"CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o" \
"CMakeFiles/observatory.dir/src/main.cpp.o"

# External object files for target observatory
observatory_EXTERNAL_OBJECTS =

observatory: CMakeFiles/observatory.dir/src/models/Camera.cpp.o
observatory: CMakeFiles/observatory.dir/src/models/Image.cpp.o
observatory: CMakeFiles/observatory.dir/src/models/Observatory.cpp.o
observatory: CMakeFiles/observatory.dir/src/models/Photo.cpp.o
observatory: CMakeFiles/observatory.dir/src/models/ObservatorySimulator.cpp.o
observatory: CMakeFiles/observatory.dir/src/utils/Logger.cpp.o
observatory: CMakeFiles/observatory.dir/src/utils/IPC/signals/SignalHandler.cpp.o
observatory: CMakeFiles/observatory.dir/src/main.cpp.o
observatory: CMakeFiles/observatory.dir/build.make
observatory: CMakeFiles/observatory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable observatory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/observatory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/observatory.dir/build: observatory

.PHONY : CMakeFiles/observatory.dir/build

CMakeFiles/observatory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/observatory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/observatory.dir/clean

CMakeFiles/observatory.dir/depend:
	cd "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1" "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1" "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build" "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build" "/home/agus/Escritorio/Proyectos/Este Cuatri/75.59 Tecnicas concurrente/Tps/Tp1/7559Tp1/build/CMakeFiles/observatory.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/observatory.dir/depend

