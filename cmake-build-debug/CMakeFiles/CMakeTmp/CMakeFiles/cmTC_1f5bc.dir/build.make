# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp

# Include any dependencies generated for this target.
include CMakeFiles/cmTC_1f5bc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmTC_1f5bc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmTC_1f5bc.dir/flags.make

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj: CMakeFiles/cmTC_1f5bc.dir/flags.make
CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj: C:/Users/somebody/Documents/GitHub/OS_P1/cmake-build-debug/CMakeFiles/feature_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj"
	E:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cmTC_1f5bc.dir\feature_tests.c.obj   -c C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\feature_tests.c

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.i: cmake_force
	@echo Preprocessing C source to CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.i
	E:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\feature_tests.c > CMakeFiles\cmTC_1f5bc.dir\feature_tests.c.i

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.s: cmake_force
	@echo Compiling C source to assembly CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.s
	E:\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\feature_tests.c -o CMakeFiles\cmTC_1f5bc.dir\feature_tests.c.s

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.requires:

.PHONY : CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.requires

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.provides: CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.requires
	$(MAKE) -f CMakeFiles\cmTC_1f5bc.dir\build.make CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.provides.build
.PHONY : CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.provides

CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.provides.build: CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj


# Object files for target cmTC_1f5bc
cmTC_1f5bc_OBJECTS = \
"CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj"

# External object files for target cmTC_1f5bc
cmTC_1f5bc_EXTERNAL_OBJECTS =

cmTC_1f5bc.exe: CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj
cmTC_1f5bc.exe: CMakeFiles/cmTC_1f5bc.dir/build.make
cmTC_1f5bc.exe: CMakeFiles/cmTC_1f5bc.dir/linklibs.rsp
cmTC_1f5bc.exe: CMakeFiles/cmTC_1f5bc.dir/objects1.rsp
cmTC_1f5bc.exe: CMakeFiles/cmTC_1f5bc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cmTC_1f5bc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cmTC_1f5bc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmTC_1f5bc.dir/build: cmTC_1f5bc.exe

.PHONY : CMakeFiles/cmTC_1f5bc.dir/build

CMakeFiles/cmTC_1f5bc.dir/requires: CMakeFiles/cmTC_1f5bc.dir/feature_tests.c.obj.requires

.PHONY : CMakeFiles/cmTC_1f5bc.dir/requires

CMakeFiles/cmTC_1f5bc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cmTC_1f5bc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cmTC_1f5bc.dir/clean

CMakeFiles/cmTC_1f5bc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp C:\Users\somebody\Documents\GitHub\OS_P1\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles\cmTC_1f5bc.dir\DependInfo.cmake
.PHONY : CMakeFiles/cmTC_1f5bc.dir/depend

