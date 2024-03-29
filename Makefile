# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/thomas/YangMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/YangMake

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thomas/YangMake/CMakeFiles /home/thomas/YangMake/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thomas/YangMake/CMakeFiles 0
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
# Target rules for targets named yangMake

# Build rule for target.
yangMake: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 yangMake
.PHONY : yangMake

# fast build rule for target.
yangMake/fast:
	$(MAKE) -f CMakeFiles/yangMake.dir/build.make CMakeFiles/yangMake.dir/build
.PHONY : yangMake/fast

#=============================================================================
# Target rules for targets named testYangMake

# Build rule for target.
testYangMake: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testYangMake
.PHONY : testYangMake

# fast build rule for target.
testYangMake/fast:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/build
.PHONY : testYangMake/fast

src/main.o: src/main.cc.o

.PHONY : src/main.o

# target to build an object file
src/main.cc.o:
	$(MAKE) -f CMakeFiles/yangMake.dir/build.make CMakeFiles/yangMake.dir/src/main.cc.o
.PHONY : src/main.cc.o

src/main.i: src/main.cc.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cc.i:
	$(MAKE) -f CMakeFiles/yangMake.dir/build.make CMakeFiles/yangMake.dir/src/main.cc.i
.PHONY : src/main.cc.i

src/main.s: src/main.cc.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cc.s:
	$(MAKE) -f CMakeFiles/yangMake.dir/build.make CMakeFiles/yangMake.dir/src/main.cc.s
.PHONY : src/main.cc.s

test/TestDependencyGraph.o: test/TestDependencyGraph.cc.o

.PHONY : test/TestDependencyGraph.o

# target to build an object file
test/TestDependencyGraph.cc.o:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestDependencyGraph.cc.o
.PHONY : test/TestDependencyGraph.cc.o

test/TestDependencyGraph.i: test/TestDependencyGraph.cc.i

.PHONY : test/TestDependencyGraph.i

# target to preprocess a source file
test/TestDependencyGraph.cc.i:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestDependencyGraph.cc.i
.PHONY : test/TestDependencyGraph.cc.i

test/TestDependencyGraph.s: test/TestDependencyGraph.cc.s

.PHONY : test/TestDependencyGraph.s

# target to generate assembly for a file
test/TestDependencyGraph.cc.s:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestDependencyGraph.cc.s
.PHONY : test/TestDependencyGraph.cc.s

test/TestExecution.o: test/TestExecution.cc.o

.PHONY : test/TestExecution.o

# target to build an object file
test/TestExecution.cc.o:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestExecution.cc.o
.PHONY : test/TestExecution.cc.o

test/TestExecution.i: test/TestExecution.cc.i

.PHONY : test/TestExecution.i

# target to preprocess a source file
test/TestExecution.cc.i:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestExecution.cc.i
.PHONY : test/TestExecution.cc.i

test/TestExecution.s: test/TestExecution.cc.s

.PHONY : test/TestExecution.s

# target to generate assembly for a file
test/TestExecution.cc.s:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestExecution.cc.s
.PHONY : test/TestExecution.cc.s

test/TestMakeProcedure.o: test/TestMakeProcedure.cc.o

.PHONY : test/TestMakeProcedure.o

# target to build an object file
test/TestMakeProcedure.cc.o:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestMakeProcedure.cc.o
.PHONY : test/TestMakeProcedure.cc.o

test/TestMakeProcedure.i: test/TestMakeProcedure.cc.i

.PHONY : test/TestMakeProcedure.i

# target to preprocess a source file
test/TestMakeProcedure.cc.i:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestMakeProcedure.cc.i
.PHONY : test/TestMakeProcedure.cc.i

test/TestMakeProcedure.s: test/TestMakeProcedure.cc.s

.PHONY : test/TestMakeProcedure.s

# target to generate assembly for a file
test/TestMakeProcedure.cc.s:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/TestMakeProcedure.cc.s
.PHONY : test/TestMakeProcedure.cc.s

test/test.o: test/test.cc.o

.PHONY : test/test.o

# target to build an object file
test/test.cc.o:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/test.cc.o
.PHONY : test/test.cc.o

test/test.i: test/test.cc.i

.PHONY : test/test.i

# target to preprocess a source file
test/test.cc.i:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/test.cc.i
.PHONY : test/test.cc.i

test/test.s: test/test.cc.s

.PHONY : test/test.s

# target to generate assembly for a file
test/test.cc.s:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/test.cc.s
.PHONY : test/test.cc.s

test/testParse.o: test/testParse.cc.o

.PHONY : test/testParse.o

# target to build an object file
test/testParse.cc.o:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/testParse.cc.o
.PHONY : test/testParse.cc.o

test/testParse.i: test/testParse.cc.i

.PHONY : test/testParse.i

# target to preprocess a source file
test/testParse.cc.i:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/testParse.cc.i
.PHONY : test/testParse.cc.i

test/testParse.s: test/testParse.cc.s

.PHONY : test/testParse.s

# target to generate assembly for a file
test/testParse.cc.s:
	$(MAKE) -f CMakeFiles/testYangMake.dir/build.make CMakeFiles/testYangMake.dir/test/testParse.cc.s
.PHONY : test/testParse.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... yangMake"
	@echo "... testYangMake"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... test/TestDependencyGraph.o"
	@echo "... test/TestDependencyGraph.i"
	@echo "... test/TestDependencyGraph.s"
	@echo "... test/TestExecution.o"
	@echo "... test/TestExecution.i"
	@echo "... test/TestExecution.s"
	@echo "... test/TestMakeProcedure.o"
	@echo "... test/TestMakeProcedure.i"
	@echo "... test/TestMakeProcedure.s"
	@echo "... test/test.o"
	@echo "... test/test.i"
	@echo "... test/test.s"
	@echo "... test/testParse.o"
	@echo "... test/testParse.i"
	@echo "... test/testParse.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

