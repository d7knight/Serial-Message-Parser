# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dave/ClionProjects/skyladders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dave/ClionProjects/skyladders

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dave/ClionProjects/skyladders/CMakeFiles /home/dave/ClionProjects/skyladders/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dave/ClionProjects/skyladders/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named skyladders

# Build rule for target.
skyladders: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 skyladders
.PHONY : skyladders

# fast build rule for target.
skyladders/fast:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/build
.PHONY : skyladders/fast

helper.o: helper.cpp.o
.PHONY : helper.o

# target to build an object file
helper.cpp.o:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/helper.cpp.o
.PHONY : helper.cpp.o

helper.i: helper.cpp.i
.PHONY : helper.i

# target to preprocess a source file
helper.cpp.i:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/helper.cpp.i
.PHONY : helper.cpp.i

helper.s: helper.cpp.s
.PHONY : helper.s

# target to generate assembly for a file
helper.cpp.s:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/helper.cpp.s
.PHONY : helper.cpp.s

serial_adapter.o: serial_adapter.cpp.o
.PHONY : serial_adapter.o

# target to build an object file
serial_adapter.cpp.o:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_adapter.cpp.o
.PHONY : serial_adapter.cpp.o

serial_adapter.i: serial_adapter.cpp.i
.PHONY : serial_adapter.i

# target to preprocess a source file
serial_adapter.cpp.i:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_adapter.cpp.i
.PHONY : serial_adapter.cpp.i

serial_adapter.s: serial_adapter.cpp.s
.PHONY : serial_adapter.s

# target to generate assembly for a file
serial_adapter.cpp.s:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_adapter.cpp.s
.PHONY : serial_adapter.cpp.s

serial_message_parser.o: serial_message_parser.cpp.o
.PHONY : serial_message_parser.o

# target to build an object file
serial_message_parser.cpp.o:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_message_parser.cpp.o
.PHONY : serial_message_parser.cpp.o

serial_message_parser.i: serial_message_parser.cpp.i
.PHONY : serial_message_parser.i

# target to preprocess a source file
serial_message_parser.cpp.i:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_message_parser.cpp.i
.PHONY : serial_message_parser.cpp.i

serial_message_parser.s: serial_message_parser.cpp.s
.PHONY : serial_message_parser.s

# target to generate assembly for a file
serial_message_parser.cpp.s:
	$(MAKE) -f CMakeFiles/skyladders.dir/build.make CMakeFiles/skyladders.dir/serial_message_parser.cpp.s
.PHONY : serial_message_parser.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... skyladders"
	@echo "... helper.o"
	@echo "... helper.i"
	@echo "... helper.s"
	@echo "... serial_adapter.o"
	@echo "... serial_adapter.i"
	@echo "... serial_adapter.s"
	@echo "... serial_message_parser.o"
	@echo "... serial_message_parser.i"
	@echo "... serial_message_parser.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

