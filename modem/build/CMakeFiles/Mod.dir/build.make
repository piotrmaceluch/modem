# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /home/maceluch/Desktop/MODEM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maceluch/Desktop/MODEM/build

# Include any dependencies generated for this target.
include CMakeFiles/Mod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Mod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mod.dir/flags.make

CMakeFiles/Mod.dir/functions.cpp.o: CMakeFiles/Mod.dir/flags.make
CMakeFiles/Mod.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maceluch/Desktop/MODEM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mod.dir/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Mod.dir/functions.cpp.o -c /home/maceluch/Desktop/MODEM/functions.cpp

CMakeFiles/Mod.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Mod.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maceluch/Desktop/MODEM/functions.cpp > CMakeFiles/Mod.dir/functions.cpp.i

CMakeFiles/Mod.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Mod.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maceluch/Desktop/MODEM/functions.cpp -o CMakeFiles/Mod.dir/functions.cpp.s

CMakeFiles/Mod.dir/functions.cpp.o.requires:

.PHONY : CMakeFiles/Mod.dir/functions.cpp.o.requires

CMakeFiles/Mod.dir/functions.cpp.o.provides: CMakeFiles/Mod.dir/functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/Mod.dir/build.make CMakeFiles/Mod.dir/functions.cpp.o.provides.build
.PHONY : CMakeFiles/Mod.dir/functions.cpp.o.provides

CMakeFiles/Mod.dir/functions.cpp.o.provides.build: CMakeFiles/Mod.dir/functions.cpp.o


# Object files for target Mod
Mod_OBJECTS = \
"CMakeFiles/Mod.dir/functions.cpp.o"

# External object files for target Mod
Mod_EXTERNAL_OBJECTS =

Mod: CMakeFiles/Mod.dir/functions.cpp.o
Mod: CMakeFiles/Mod.dir/build.make
Mod: CMakeFiles/Mod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maceluch/Desktop/MODEM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Mod"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Mod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mod.dir/build: Mod

.PHONY : CMakeFiles/Mod.dir/build

CMakeFiles/Mod.dir/requires: CMakeFiles/Mod.dir/functions.cpp.o.requires

.PHONY : CMakeFiles/Mod.dir/requires

CMakeFiles/Mod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mod.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mod.dir/clean

CMakeFiles/Mod.dir/depend:
	cd /home/maceluch/Desktop/MODEM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maceluch/Desktop/MODEM /home/maceluch/Desktop/MODEM /home/maceluch/Desktop/MODEM/build /home/maceluch/Desktop/MODEM/build /home/maceluch/Desktop/MODEM/build/CMakeFiles/Mod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Mod.dir/depend
