# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build

# Include any dependencies generated for this target.
include CMakeFiles/ceres_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ceres_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ceres_example.dir/flags.make

CMakeFiles/ceres_example.dir/ceres_example.cpp.o: CMakeFiles/ceres_example.dir/flags.make
CMakeFiles/ceres_example.dir/ceres_example.cpp.o: ../ceres_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ceres_example.dir/ceres_example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ceres_example.dir/ceres_example.cpp.o -c /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/ceres_example.cpp

CMakeFiles/ceres_example.dir/ceres_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ceres_example.dir/ceres_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/ceres_example.cpp > CMakeFiles/ceres_example.dir/ceres_example.cpp.i

CMakeFiles/ceres_example.dir/ceres_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ceres_example.dir/ceres_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/ceres_example.cpp -o CMakeFiles/ceres_example.dir/ceres_example.cpp.s

# Object files for target ceres_example
ceres_example_OBJECTS = \
"CMakeFiles/ceres_example.dir/ceres_example.cpp.o"

# External object files for target ceres_example
ceres_example_EXTERNAL_OBJECTS =

ceres_example: CMakeFiles/ceres_example.dir/ceres_example.cpp.o
ceres_example: CMakeFiles/ceres_example.dir/build.make
ceres_example: /usr/local/lib/libceres.a
ceres_example: /usr/lib/x86_64-linux-gnu/libglog.so
ceres_example: /usr/lib/x86_64-linux-gnu/libgflags.so.2.2.2
ceres_example: /usr/lib/x86_64-linux-gnu/libspqr.so
ceres_example: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
ceres_example: /usr/lib/x86_64-linux-gnu/libtbb.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcholmod.so
ceres_example: /usr/lib/x86_64-linux-gnu/libccolamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcolamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/liblapack.so
ceres_example: /usr/lib/x86_64-linux-gnu/libf77blas.so
ceres_example: /usr/lib/x86_64-linux-gnu/libatlas.so
ceres_example: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
ceres_example: /usr/lib/x86_64-linux-gnu/librt.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcxsparse.so
ceres_example: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
ceres_example: /usr/lib/x86_64-linux-gnu/libtbb.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcholmod.so
ceres_example: /usr/lib/x86_64-linux-gnu/libccolamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcolamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/libamd.so
ceres_example: /usr/lib/x86_64-linux-gnu/liblapack.so
ceres_example: /usr/lib/x86_64-linux-gnu/libf77blas.so
ceres_example: /usr/lib/x86_64-linux-gnu/libatlas.so
ceres_example: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
ceres_example: /usr/lib/x86_64-linux-gnu/librt.so
ceres_example: /usr/lib/x86_64-linux-gnu/libcxsparse.so
ceres_example: CMakeFiles/ceres_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ceres_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ceres_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ceres_example.dir/build: ceres_example

.PHONY : CMakeFiles/ceres_example.dir/build

CMakeFiles/ceres_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ceres_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ceres_example.dir/clean

CMakeFiles/ceres_example.dir/depend:
	cd /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build /home/patience/Documents/VSCode/Repos/Codes_C++/cv_learning/TEST_TEMP/ceres_test/build/CMakeFiles/ceres_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ceres_example.dir/depend

