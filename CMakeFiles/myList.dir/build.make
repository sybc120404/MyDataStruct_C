# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cai/share/codeSpace/myList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cai/share/codeSpace/myList

# Include any dependencies generated for this target.
include CMakeFiles/myList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myList.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myList.dir/flags.make

CMakeFiles/myList.dir/src/main.c.o: CMakeFiles/myList.dir/flags.make
CMakeFiles/myList.dir/src/main.c.o: src/main.c
CMakeFiles/myList.dir/src/main.c.o: CMakeFiles/myList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cai/share/codeSpace/myList/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myList.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/myList.dir/src/main.c.o -MF CMakeFiles/myList.dir/src/main.c.o.d -o CMakeFiles/myList.dir/src/main.c.o -c /home/cai/share/codeSpace/myList/src/main.c

CMakeFiles/myList.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/myList.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cai/share/codeSpace/myList/src/main.c > CMakeFiles/myList.dir/src/main.c.i

CMakeFiles/myList.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/myList.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cai/share/codeSpace/myList/src/main.c -o CMakeFiles/myList.dir/src/main.c.s

# Object files for target myList
myList_OBJECTS = \
"CMakeFiles/myList.dir/src/main.c.o"

# External object files for target myList
myList_EXTERNAL_OBJECTS =

myList: CMakeFiles/myList.dir/src/main.c.o
myList: CMakeFiles/myList.dir/build.make
myList: liblistLib.a
myList: CMakeFiles/myList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/cai/share/codeSpace/myList/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable myList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myList.dir/build: myList
.PHONY : CMakeFiles/myList.dir/build

CMakeFiles/myList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myList.dir/clean

CMakeFiles/myList.dir/depend:
	cd /home/cai/share/codeSpace/myList && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cai/share/codeSpace/myList /home/cai/share/codeSpace/myList /home/cai/share/codeSpace/myList /home/cai/share/codeSpace/myList /home/cai/share/codeSpace/myList/CMakeFiles/myList.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/myList.dir/depend

