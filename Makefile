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
CMAKE_SOURCE_DIR = /home/thiago/Desktop/Fiuba/Taller1/tp-final-taller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiago/Desktop/Fiuba/Taller1/tp-final-taller

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thiago/Desktop/Fiuba/Taller1/tp-final-taller/CMakeFiles /home/thiago/Desktop/Fiuba/Taller1/tp-final-taller/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thiago/Desktop/Fiuba/Taller1/tp-final-taller/CMakeFiles 0
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
# Target rules for targets named WolfensteinTest

# Build rule for target.
WolfensteinTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 WolfensteinTest
.PHONY : WolfensteinTest

# fast build rule for target.
WolfensteinTest/fast:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/build
.PHONY : WolfensteinTest/fast

common/src/Socket/SocketCommunication.o: common/src/Socket/SocketCommunication.cpp.o

.PHONY : common/src/Socket/SocketCommunication.o

# target to build an object file
common/src/Socket/SocketCommunication.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketCommunication.cpp.o
.PHONY : common/src/Socket/SocketCommunication.cpp.o

common/src/Socket/SocketCommunication.i: common/src/Socket/SocketCommunication.cpp.i

.PHONY : common/src/Socket/SocketCommunication.i

# target to preprocess a source file
common/src/Socket/SocketCommunication.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketCommunication.cpp.i
.PHONY : common/src/Socket/SocketCommunication.cpp.i

common/src/Socket/SocketCommunication.s: common/src/Socket/SocketCommunication.cpp.s

.PHONY : common/src/Socket/SocketCommunication.s

# target to generate assembly for a file
common/src/Socket/SocketCommunication.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketCommunication.cpp.s
.PHONY : common/src/Socket/SocketCommunication.cpp.s

common/src/Socket/SocketListener.o: common/src/Socket/SocketListener.cpp.o

.PHONY : common/src/Socket/SocketListener.o

# target to build an object file
common/src/Socket/SocketListener.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketListener.cpp.o
.PHONY : common/src/Socket/SocketListener.cpp.o

common/src/Socket/SocketListener.i: common/src/Socket/SocketListener.cpp.i

.PHONY : common/src/Socket/SocketListener.i

# target to preprocess a source file
common/src/Socket/SocketListener.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketListener.cpp.i
.PHONY : common/src/Socket/SocketListener.cpp.i

common/src/Socket/SocketListener.s: common/src/Socket/SocketListener.cpp.s

.PHONY : common/src/Socket/SocketListener.s

# target to generate assembly for a file
common/src/Socket/SocketListener.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Socket/SocketListener.cpp.s
.PHONY : common/src/Socket/SocketListener.cpp.s

common/src/Thread/Thread.o: common/src/Thread/Thread.cpp.o

.PHONY : common/src/Thread/Thread.o

# target to build an object file
common/src/Thread/Thread.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Thread/Thread.cpp.o
.PHONY : common/src/Thread/Thread.cpp.o

common/src/Thread/Thread.i: common/src/Thread/Thread.cpp.i

.PHONY : common/src/Thread/Thread.i

# target to preprocess a source file
common/src/Thread/Thread.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Thread/Thread.cpp.i
.PHONY : common/src/Thread/Thread.cpp.i

common/src/Thread/Thread.s: common/src/Thread/Thread.cpp.s

.PHONY : common/src/Thread/Thread.s

# target to generate assembly for a file
common/src/Thread/Thread.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/common/src/Thread/Thread.cpp.s
.PHONY : common/src/Thread/Thread.cpp.s

server/src/Match/Match.o: server/src/Match/Match.cpp.o

.PHONY : server/src/Match/Match.o

# target to build an object file
server/src/Match/Match.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/Match.cpp.o
.PHONY : server/src/Match/Match.cpp.o

server/src/Match/Match.i: server/src/Match/Match.cpp.i

.PHONY : server/src/Match/Match.i

# target to preprocess a source file
server/src/Match/Match.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/Match.cpp.i
.PHONY : server/src/Match/Match.cpp.i

server/src/Match/Match.s: server/src/Match/Match.cpp.s

.PHONY : server/src/Match/Match.s

# target to generate assembly for a file
server/src/Match/Match.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/Match.cpp.s
.PHONY : server/src/Match/Match.cpp.s

server/src/Match/MatchList.o: server/src/Match/MatchList.cpp.o

.PHONY : server/src/Match/MatchList.o

# target to build an object file
server/src/Match/MatchList.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/MatchList.cpp.o
.PHONY : server/src/Match/MatchList.cpp.o

server/src/Match/MatchList.i: server/src/Match/MatchList.cpp.i

.PHONY : server/src/Match/MatchList.i

# target to preprocess a source file
server/src/Match/MatchList.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/MatchList.cpp.i
.PHONY : server/src/Match/MatchList.cpp.i

server/src/Match/MatchList.s: server/src/Match/MatchList.cpp.s

.PHONY : server/src/Match/MatchList.s

# target to generate assembly for a file
server/src/Match/MatchList.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Match/MatchList.cpp.s
.PHONY : server/src/Match/MatchList.cpp.s

server/src/Server/ClientAccepter.o: server/src/Server/ClientAccepter.cpp.o

.PHONY : server/src/Server/ClientAccepter.o

# target to build an object file
server/src/Server/ClientAccepter.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientAccepter.cpp.o
.PHONY : server/src/Server/ClientAccepter.cpp.o

server/src/Server/ClientAccepter.i: server/src/Server/ClientAccepter.cpp.i

.PHONY : server/src/Server/ClientAccepter.i

# target to preprocess a source file
server/src/Server/ClientAccepter.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientAccepter.cpp.i
.PHONY : server/src/Server/ClientAccepter.cpp.i

server/src/Server/ClientAccepter.s: server/src/Server/ClientAccepter.cpp.s

.PHONY : server/src/Server/ClientAccepter.s

# target to generate assembly for a file
server/src/Server/ClientAccepter.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientAccepter.cpp.s
.PHONY : server/src/Server/ClientAccepter.cpp.s

server/src/Server/ClientCommunication.o: server/src/Server/ClientCommunication.cpp.o

.PHONY : server/src/Server/ClientCommunication.o

# target to build an object file
server/src/Server/ClientCommunication.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientCommunication.cpp.o
.PHONY : server/src/Server/ClientCommunication.cpp.o

server/src/Server/ClientCommunication.i: server/src/Server/ClientCommunication.cpp.i

.PHONY : server/src/Server/ClientCommunication.i

# target to preprocess a source file
server/src/Server/ClientCommunication.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientCommunication.cpp.i
.PHONY : server/src/Server/ClientCommunication.cpp.i

server/src/Server/ClientCommunication.s: server/src/Server/ClientCommunication.cpp.s

.PHONY : server/src/Server/ClientCommunication.s

# target to generate assembly for a file
server/src/Server/ClientCommunication.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/ClientCommunication.cpp.s
.PHONY : server/src/Server/ClientCommunication.cpp.s

server/src/Server/Server.o: server/src/Server/Server.cpp.o

.PHONY : server/src/Server/Server.o

# target to build an object file
server/src/Server/Server.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/Server.cpp.o
.PHONY : server/src/Server/Server.cpp.o

server/src/Server/Server.i: server/src/Server/Server.cpp.i

.PHONY : server/src/Server/Server.i

# target to preprocess a source file
server/src/Server/Server.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/Server.cpp.i
.PHONY : server/src/Server/Server.cpp.i

server/src/Server/Server.s: server/src/Server/Server.cpp.s

.PHONY : server/src/Server/Server.s

# target to generate assembly for a file
server/src/Server/Server.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/server/src/Server/Server.cpp.s
.PHONY : server/src/Server/Server.cpp.s

test/test.o: test/test.cpp.o

.PHONY : test/test.o

# target to build an object file
test/test.cpp.o:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/test/test.cpp.o
.PHONY : test/test.cpp.o

test/test.i: test/test.cpp.i

.PHONY : test/test.i

# target to preprocess a source file
test/test.cpp.i:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/test/test.cpp.i
.PHONY : test/test.cpp.i

test/test.s: test/test.cpp.s

.PHONY : test/test.s

# target to generate assembly for a file
test/test.cpp.s:
	$(MAKE) -f CMakeFiles/WolfensteinTest.dir/build.make CMakeFiles/WolfensteinTest.dir/test/test.cpp.s
.PHONY : test/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... WolfensteinTest"
	@echo "... edit_cache"
	@echo "... common/src/Socket/SocketCommunication.o"
	@echo "... common/src/Socket/SocketCommunication.i"
	@echo "... common/src/Socket/SocketCommunication.s"
	@echo "... common/src/Socket/SocketListener.o"
	@echo "... common/src/Socket/SocketListener.i"
	@echo "... common/src/Socket/SocketListener.s"
	@echo "... common/src/Thread/Thread.o"
	@echo "... common/src/Thread/Thread.i"
	@echo "... common/src/Thread/Thread.s"
	@echo "... server/src/Match/Match.o"
	@echo "... server/src/Match/Match.i"
	@echo "... server/src/Match/Match.s"
	@echo "... server/src/Match/MatchList.o"
	@echo "... server/src/Match/MatchList.i"
	@echo "... server/src/Match/MatchList.s"
	@echo "... server/src/Server/ClientAccepter.o"
	@echo "... server/src/Server/ClientAccepter.i"
	@echo "... server/src/Server/ClientAccepter.s"
	@echo "... server/src/Server/ClientCommunication.o"
	@echo "... server/src/Server/ClientCommunication.i"
	@echo "... server/src/Server/ClientCommunication.s"
	@echo "... server/src/Server/Server.o"
	@echo "... server/src/Server/Server.i"
	@echo "... server/src/Server/Server.s"
	@echo "... test/test.o"
	@echo "... test/test.i"
	@echo "... test/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
