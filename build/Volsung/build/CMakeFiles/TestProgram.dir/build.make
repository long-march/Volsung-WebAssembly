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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dominik/Documents/VolsungWebFrontend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dominik/Documents/VolsungWebFrontend/build

# Include any dependencies generated for this target.
include Volsung/build/CMakeFiles/TestProgram.dir/depend.make

# Include the progress variables for this target.
include Volsung/build/CMakeFiles/TestProgram.dir/progress.make

# Include the compile flags for this target's objects.
include Volsung/build/CMakeFiles/TestProgram.dir/flags.make

Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o: Volsung/build/CMakeFiles/TestProgram.dir/flags.make
Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o: ../Volsung/test/TestProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/Documents/VolsungWebFrontend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o"
	cd /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o -c /home/dominik/Documents/VolsungWebFrontend/Volsung/test/TestProgram.cpp

Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestProgram.dir/test/TestProgram.cpp.i"
	cd /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dominik/Documents/VolsungWebFrontend/Volsung/test/TestProgram.cpp > CMakeFiles/TestProgram.dir/test/TestProgram.cpp.i

Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestProgram.dir/test/TestProgram.cpp.s"
	cd /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dominik/Documents/VolsungWebFrontend/Volsung/test/TestProgram.cpp -o CMakeFiles/TestProgram.dir/test/TestProgram.cpp.s

# Object files for target TestProgram
TestProgram_OBJECTS = \
"CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o"

# External object files for target TestProgram
TestProgram_EXTERNAL_OBJECTS =

Volsung/build/TestProgram: Volsung/build/CMakeFiles/TestProgram.dir/test/TestProgram.cpp.o
Volsung/build/TestProgram: Volsung/build/CMakeFiles/TestProgram.dir/build.make
Volsung/build/TestProgram: Volsung/lib/libVolsung.a
Volsung/build/TestProgram: Volsung/build/CMakeFiles/TestProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dominik/Documents/VolsungWebFrontend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestProgram"
	cd /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Volsung/build/CMakeFiles/TestProgram.dir/build: Volsung/build/TestProgram

.PHONY : Volsung/build/CMakeFiles/TestProgram.dir/build

Volsung/build/CMakeFiles/TestProgram.dir/clean:
	cd /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build && $(CMAKE_COMMAND) -P CMakeFiles/TestProgram.dir/cmake_clean.cmake
.PHONY : Volsung/build/CMakeFiles/TestProgram.dir/clean

Volsung/build/CMakeFiles/TestProgram.dir/depend:
	cd /home/dominik/Documents/VolsungWebFrontend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dominik/Documents/VolsungWebFrontend /home/dominik/Documents/VolsungWebFrontend/Volsung /home/dominik/Documents/VolsungWebFrontend/build /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build /home/dominik/Documents/VolsungWebFrontend/build/Volsung/build/CMakeFiles/TestProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Volsung/build/CMakeFiles/TestProgram.dir/depend

