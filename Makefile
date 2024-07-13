# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anno/CLionProjects/assn1/ass1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anno/CLionProjects/assn1/ass1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/opt/homebrew/Cellar/cmake/3.29.5/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.29.5/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.29.5/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/anno/CLionProjects/assn1/ass1/CMakeFiles /Users/anno/CLionProjects/assn1/ass1//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/anno/CLionProjects/assn1/ass1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named catch2_main

# Build rule for target.
catch2_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 catch2_main
.PHONY : catch2_main

# fast build rule for target.
catch2_main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/catch2_main.dir/build.make CMakeFiles/catch2_main.dir/build
.PHONY : catch2_main/fast

#=============================================================================
# Target rules for targets named word_ladder

# Build rule for target.
word_ladder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 word_ladder
.PHONY : word_ladder

# fast build rule for target.
word_ladder/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder.dir/build.make CMakeFiles/word_ladder.dir/build
.PHONY : word_ladder/fast

#=============================================================================
# Target rules for targets named debugging

# Build rule for target.
debugging: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 debugging
.PHONY : debugging

# fast build rule for target.
debugging/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/debugging.dir/build.make CMakeFiles/debugging.dir/build
.PHONY : debugging/fast

#=============================================================================
# Target rules for targets named word_ladder_test_exe

# Build rule for target.
word_ladder_test_exe: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 word_ladder_test_exe
.PHONY : word_ladder_test_exe

# fast build rule for target.
word_ladder_test_exe/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_test_exe.dir/build.make CMakeFiles/word_ladder_test_exe.dir/build
.PHONY : word_ladder_test_exe/fast

#=============================================================================
# Target rules for targets named word_ladder_benchmark_exe

# Build rule for target.
word_ladder_benchmark_exe: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 word_ladder_benchmark_exe
.PHONY : word_ladder_benchmark_exe

# fast build rule for target.
word_ladder_benchmark_exe/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_benchmark_exe.dir/build.make CMakeFiles/word_ladder_benchmark_exe.dir/build
.PHONY : word_ladder_benchmark_exe/fast

lib/catch2_main.o: lib/catch2_main.cpp.o
.PHONY : lib/catch2_main.o

# target to build an object file
lib/catch2_main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/catch2_main.dir/build.make CMakeFiles/catch2_main.dir/lib/catch2_main.cpp.o
.PHONY : lib/catch2_main.cpp.o

lib/catch2_main.i: lib/catch2_main.cpp.i
.PHONY : lib/catch2_main.i

# target to preprocess a source file
lib/catch2_main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/catch2_main.dir/build.make CMakeFiles/catch2_main.dir/lib/catch2_main.cpp.i
.PHONY : lib/catch2_main.cpp.i

lib/catch2_main.s: lib/catch2_main.cpp.s
.PHONY : lib/catch2_main.s

# target to generate assembly for a file
lib/catch2_main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/catch2_main.dir/build.make CMakeFiles/catch2_main.dir/lib/catch2_main.cpp.s
.PHONY : lib/catch2_main.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/debugging.dir/build.make CMakeFiles/debugging.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/debugging.dir/build.make CMakeFiles/debugging.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/debugging.dir/build.make CMakeFiles/debugging.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/word_ladder.o: src/word_ladder.cpp.o
.PHONY : src/word_ladder.o

# target to build an object file
src/word_ladder.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder.dir/build.make CMakeFiles/word_ladder.dir/src/word_ladder.cpp.o
.PHONY : src/word_ladder.cpp.o

src/word_ladder.i: src/word_ladder.cpp.i
.PHONY : src/word_ladder.i

# target to preprocess a source file
src/word_ladder.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder.dir/build.make CMakeFiles/word_ladder.dir/src/word_ladder.cpp.i
.PHONY : src/word_ladder.cpp.i

src/word_ladder.s: src/word_ladder.cpp.s
.PHONY : src/word_ladder.s

# target to generate assembly for a file
src/word_ladder.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder.dir/build.make CMakeFiles/word_ladder.dir/src/word_ladder.cpp.s
.PHONY : src/word_ladder.cpp.s

src/word_ladder.test.o: src/word_ladder.test.cpp.o
.PHONY : src/word_ladder.test.o

# target to build an object file
src/word_ladder.test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_test_exe.dir/build.make CMakeFiles/word_ladder_test_exe.dir/src/word_ladder.test.cpp.o
.PHONY : src/word_ladder.test.cpp.o

src/word_ladder.test.i: src/word_ladder.test.cpp.i
.PHONY : src/word_ladder.test.i

# target to preprocess a source file
src/word_ladder.test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_test_exe.dir/build.make CMakeFiles/word_ladder_test_exe.dir/src/word_ladder.test.cpp.i
.PHONY : src/word_ladder.test.cpp.i

src/word_ladder.test.s: src/word_ladder.test.cpp.s
.PHONY : src/word_ladder.test.s

# target to generate assembly for a file
src/word_ladder.test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_test_exe.dir/build.make CMakeFiles/word_ladder_test_exe.dir/src/word_ladder.test.cpp.s
.PHONY : src/word_ladder.test.cpp.s

src/word_ladder_benchmark.test.o: src/word_ladder_benchmark.test.cpp.o
.PHONY : src/word_ladder_benchmark.test.o

# target to build an object file
src/word_ladder_benchmark.test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_benchmark_exe.dir/build.make CMakeFiles/word_ladder_benchmark_exe.dir/src/word_ladder_benchmark.test.cpp.o
.PHONY : src/word_ladder_benchmark.test.cpp.o

src/word_ladder_benchmark.test.i: src/word_ladder_benchmark.test.cpp.i
.PHONY : src/word_ladder_benchmark.test.i

# target to preprocess a source file
src/word_ladder_benchmark.test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_benchmark_exe.dir/build.make CMakeFiles/word_ladder_benchmark_exe.dir/src/word_ladder_benchmark.test.cpp.i
.PHONY : src/word_ladder_benchmark.test.cpp.i

src/word_ladder_benchmark.test.s: src/word_ladder_benchmark.test.cpp.s
.PHONY : src/word_ladder_benchmark.test.s

# target to generate assembly for a file
src/word_ladder_benchmark.test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/word_ladder_benchmark_exe.dir/build.make CMakeFiles/word_ladder_benchmark_exe.dir/src/word_ladder_benchmark.test.cpp.s
.PHONY : src/word_ladder_benchmark.test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... catch2_main"
	@echo "... debugging"
	@echo "... word_ladder"
	@echo "... word_ladder_benchmark_exe"
	@echo "... word_ladder_test_exe"
	@echo "... lib/catch2_main.o"
	@echo "... lib/catch2_main.i"
	@echo "... lib/catch2_main.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/word_ladder.o"
	@echo "... src/word_ladder.i"
	@echo "... src/word_ladder.s"
	@echo "... src/word_ladder.test.o"
	@echo "... src/word_ladder.test.i"
	@echo "... src/word_ladder.test.s"
	@echo "... src/word_ladder_benchmark.test.o"
	@echo "... src/word_ladder_benchmark.test.i"
	@echo "... src/word_ladder_benchmark.test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

