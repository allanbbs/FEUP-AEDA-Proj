# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/maruba/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/maruba/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maruba/Documents/AEDA_Proj1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maruba/Documents/AEDA_Proj1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AEDA_Proj1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AEDA_Proj1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AEDA_Proj1.dir/flags.make

CMakeFiles/AEDA_Proj1.dir/main.cpp.o: CMakeFiles/AEDA_Proj1.dir/flags.make
CMakeFiles/AEDA_Proj1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maruba/Documents/AEDA_Proj1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AEDA_Proj1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_Proj1.dir/main.cpp.o -c /home/maruba/Documents/AEDA_Proj1/main.cpp

CMakeFiles/AEDA_Proj1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_Proj1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maruba/Documents/AEDA_Proj1/main.cpp > CMakeFiles/AEDA_Proj1.dir/main.cpp.i

CMakeFiles/AEDA_Proj1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_Proj1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maruba/Documents/AEDA_Proj1/main.cpp -o CMakeFiles/AEDA_Proj1.dir/main.cpp.s

CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o: CMakeFiles/AEDA_Proj1.dir/flags.make
CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o: ../Source/Empresa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maruba/Documents/AEDA_Proj1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o -c /home/maruba/Documents/AEDA_Proj1/Source/Empresa.cpp

CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maruba/Documents/AEDA_Proj1/Source/Empresa.cpp > CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.i

CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maruba/Documents/AEDA_Proj1/Source/Empresa.cpp -o CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.s

# Object files for target AEDA_Proj1
AEDA_Proj1_OBJECTS = \
"CMakeFiles/AEDA_Proj1.dir/main.cpp.o" \
"CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o"

# External object files for target AEDA_Proj1
AEDA_Proj1_EXTERNAL_OBJECTS =

AEDA_Proj1: CMakeFiles/AEDA_Proj1.dir/main.cpp.o
AEDA_Proj1: CMakeFiles/AEDA_Proj1.dir/Source/Empresa.cpp.o
AEDA_Proj1: CMakeFiles/AEDA_Proj1.dir/build.make
AEDA_Proj1: CMakeFiles/AEDA_Proj1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maruba/Documents/AEDA_Proj1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AEDA_Proj1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AEDA_Proj1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AEDA_Proj1.dir/build: AEDA_Proj1

.PHONY : CMakeFiles/AEDA_Proj1.dir/build

CMakeFiles/AEDA_Proj1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AEDA_Proj1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AEDA_Proj1.dir/clean

CMakeFiles/AEDA_Proj1.dir/depend:
	cd /home/maruba/Documents/AEDA_Proj1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maruba/Documents/AEDA_Proj1 /home/maruba/Documents/AEDA_Proj1 /home/maruba/Documents/AEDA_Proj1/cmake-build-debug /home/maruba/Documents/AEDA_Proj1/cmake-build-debug /home/maruba/Documents/AEDA_Proj1/cmake-build-debug/CMakeFiles/AEDA_Proj1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AEDA_Proj1.dir/depend

