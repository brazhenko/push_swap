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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lreznak-/Documents/push_swap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lreznak-/Documents/push_swap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/push.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/push.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/push.dir/flags.make

CMakeFiles/push.dir/checker/main.c.o: CMakeFiles/push.dir/flags.make
CMakeFiles/push.dir/checker/main.c.o: ../checker/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lreznak-/Documents/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/push.dir/checker/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push.dir/checker/main.c.o   -c /Users/lreznak-/Documents/push_swap/checker/main.c

CMakeFiles/push.dir/checker/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push.dir/checker/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lreznak-/Documents/push_swap/checker/main.c > CMakeFiles/push.dir/checker/main.c.i

CMakeFiles/push.dir/checker/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push.dir/checker/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lreznak-/Documents/push_swap/checker/main.c -o CMakeFiles/push.dir/checker/main.c.s

CMakeFiles/push.dir/checker/error.c.o: CMakeFiles/push.dir/flags.make
CMakeFiles/push.dir/checker/error.c.o: ../checker/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lreznak-/Documents/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/push.dir/checker/error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push.dir/checker/error.c.o   -c /Users/lreznak-/Documents/push_swap/checker/error.c

CMakeFiles/push.dir/checker/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push.dir/checker/error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lreznak-/Documents/push_swap/checker/error.c > CMakeFiles/push.dir/checker/error.c.i

CMakeFiles/push.dir/checker/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push.dir/checker/error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lreznak-/Documents/push_swap/checker/error.c -o CMakeFiles/push.dir/checker/error.c.s

# Object files for target push
push_OBJECTS = \
"CMakeFiles/push.dir/checker/main.c.o" \
"CMakeFiles/push.dir/checker/error.c.o"

# External object files for target push
push_EXTERNAL_OBJECTS =

push: CMakeFiles/push.dir/checker/main.c.o
push: CMakeFiles/push.dir/checker/error.c.o
push: CMakeFiles/push.dir/build.make
push: libpush_swap_lib.a
push: libutlib.a
push: CMakeFiles/push.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lreznak-/Documents/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable push"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/push.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/push.dir/build: push

.PHONY : CMakeFiles/push.dir/build

CMakeFiles/push.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/push.dir/cmake_clean.cmake
.PHONY : CMakeFiles/push.dir/clean

CMakeFiles/push.dir/depend:
	cd /Users/lreznak-/Documents/push_swap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lreznak-/Documents/push_swap /Users/lreznak-/Documents/push_swap /Users/lreznak-/Documents/push_swap/cmake-build-debug /Users/lreznak-/Documents/push_swap/cmake-build-debug /Users/lreznak-/Documents/push_swap/cmake-build-debug/CMakeFiles/push.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/push.dir/depend
