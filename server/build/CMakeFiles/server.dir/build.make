# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/grobles/tp-final-taller/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grobles/tp-final-taller/server/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/src/main.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/main.cpp.o -c /home/grobles/tp-final-taller/server/src/main.cpp

CMakeFiles/server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/main.cpp > CMakeFiles/server.dir/src/main.cpp.i

CMakeFiles/server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/main.cpp -o CMakeFiles/server.dir/src/main.cpp.s

CMakeFiles/server.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/main.cpp.o.requires

CMakeFiles/server.dir/src/main.cpp.o.provides: CMakeFiles/server.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/main.cpp.o.provides

CMakeFiles/server.dir/src/main.cpp.o.provides.build: CMakeFiles/server.dir/src/main.cpp.o


CMakeFiles/server.dir/src/client.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/src/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/client.cpp.o -c /home/grobles/tp-final-taller/server/src/client.cpp

CMakeFiles/server.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/client.cpp > CMakeFiles/server.dir/src/client.cpp.i

CMakeFiles/server.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/client.cpp -o CMakeFiles/server.dir/src/client.cpp.s

CMakeFiles/server.dir/src/client.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/client.cpp.o.requires

CMakeFiles/server.dir/src/client.cpp.o.provides: CMakeFiles/server.dir/src/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/client.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/client.cpp.o.provides

CMakeFiles/server.dir/src/client.cpp.o.provides.build: CMakeFiles/server.dir/src/client.cpp.o


CMakeFiles/server.dir/src/server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server.cpp.o: ../src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server.cpp.o -c /home/grobles/tp-final-taller/server/src/server.cpp

CMakeFiles/server.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/server.cpp > CMakeFiles/server.dir/src/server.cpp.i

CMakeFiles/server.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/server.cpp -o CMakeFiles/server.dir/src/server.cpp.s

CMakeFiles/server.dir/src/server.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/server.cpp.o.requires

CMakeFiles/server.dir/src/server.cpp.o.provides: CMakeFiles/server.dir/src/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/server.cpp.o.provides

CMakeFiles/server.dir/src/server.cpp.o.provides.build: CMakeFiles/server.dir/src/server.cpp.o


CMakeFiles/server.dir/src/server_error.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server_error.cpp.o: ../src/server_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/src/server_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server_error.cpp.o -c /home/grobles/tp-final-taller/server/src/server_error.cpp

CMakeFiles/server.dir/src/server_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/server_error.cpp > CMakeFiles/server.dir/src/server_error.cpp.i

CMakeFiles/server.dir/src/server_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/server_error.cpp -o CMakeFiles/server.dir/src/server_error.cpp.s

CMakeFiles/server.dir/src/server_error.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/server_error.cpp.o.requires

CMakeFiles/server.dir/src/server_error.cpp.o.provides: CMakeFiles/server.dir/src/server_error.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server_error.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/server_error.cpp.o.provides

CMakeFiles/server.dir/src/server_error.cpp.o.provides.build: CMakeFiles/server.dir/src/server_error.cpp.o


CMakeFiles/server.dir/src/server_acceptor.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server_acceptor.cpp.o: ../src/server_acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/src/server_acceptor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server_acceptor.cpp.o -c /home/grobles/tp-final-taller/server/src/server_acceptor.cpp

CMakeFiles/server.dir/src/server_acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server_acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/server_acceptor.cpp > CMakeFiles/server.dir/src/server_acceptor.cpp.i

CMakeFiles/server.dir/src/server_acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server_acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/server_acceptor.cpp -o CMakeFiles/server.dir/src/server_acceptor.cpp.s

CMakeFiles/server.dir/src/server_acceptor.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/server_acceptor.cpp.o.requires

CMakeFiles/server.dir/src/server_acceptor.cpp.o.provides: CMakeFiles/server.dir/src/server_acceptor.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server_acceptor.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/server_acceptor.cpp.o.provides

CMakeFiles/server.dir/src/server_acceptor.cpp.o.provides.build: CMakeFiles/server.dir/src/server_acceptor.cpp.o


CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o: ../src/server_lobby_feeder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o -c /home/grobles/tp-final-taller/server/src/server_lobby_feeder.cpp

CMakeFiles/server.dir/src/server_lobby_feeder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server_lobby_feeder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/server_lobby_feeder.cpp > CMakeFiles/server.dir/src/server_lobby_feeder.cpp.i

CMakeFiles/server.dir/src/server_lobby_feeder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server_lobby_feeder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/server_lobby_feeder.cpp -o CMakeFiles/server.dir/src/server_lobby_feeder.cpp.s

CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.requires

CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.provides: CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.provides

CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.provides.build: CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o


CMakeFiles/server.dir/src/server_protected_clients.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server_protected_clients.cpp.o: ../src/server_protected_clients.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/src/server_protected_clients.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/server_protected_clients.cpp.o -c /home/grobles/tp-final-taller/server/src/server_protected_clients.cpp

CMakeFiles/server.dir/src/server_protected_clients.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/server_protected_clients.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/server/src/server_protected_clients.cpp > CMakeFiles/server.dir/src/server_protected_clients.cpp.i

CMakeFiles/server.dir/src/server_protected_clients.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/server_protected_clients.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/server/src/server_protected_clients.cpp -o CMakeFiles/server.dir/src/server_protected_clients.cpp.s

CMakeFiles/server.dir/src/server_protected_clients.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/src/server_protected_clients.cpp.o.requires

CMakeFiles/server.dir/src/server_protected_clients.cpp.o.provides: CMakeFiles/server.dir/src/server_protected_clients.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server_protected_clients.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/src/server_protected_clients.cpp.o.provides

CMakeFiles/server.dir/src/server_protected_clients.cpp.o.provides.build: CMakeFiles/server.dir/src/server_protected_clients.cpp.o


CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o: /home/grobles/tp-final-taller/common/src/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o -c /home/grobles/tp-final-taller/common/src/socket.cpp

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/common/src/socket.cpp > CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.i

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/common/src/socket.cpp -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.s

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.requires

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.provides: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.provides

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.provides.build: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o


CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o: /home/grobles/tp-final-taller/common/src/socket_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o -c /home/grobles/tp-final-taller/common/src/socket_error.cpp

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/common/src/socket_error.cpp > CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.i

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/common/src/socket_error.cpp -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.s

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.requires

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.provides: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.provides

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.provides.build: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o


CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o: /home/grobles/tp-final-taller/common/src/thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o -c /home/grobles/tp-final-taller/common/src/thread.cpp

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/common/src/thread.cpp > CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.i

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/common/src/thread.cpp -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.s

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.requires

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.provides: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.provides

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.provides.build: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o


CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o: /home/grobles/tp-final-taller/common/src/protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o -c /home/grobles/tp-final-taller/common/src/protocol.cpp

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/common/src/protocol.cpp > CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.i

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/common/src/protocol.cpp -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.s

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.requires

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.provides: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.provides

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.provides.build: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o


CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o: /home/grobles/tp-final-taller/common/src/protocol_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o -c /home/grobles/tp-final-taller/common/src/protocol_error.cpp

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grobles/tp-final-taller/common/src/protocol_error.cpp > CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.i

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grobles/tp-final-taller/common/src/protocol_error.cpp -o CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.s

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.requires

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.provides: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.provides

CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.provides.build: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/main.cpp.o" \
"CMakeFiles/server.dir/src/client.cpp.o" \
"CMakeFiles/server.dir/src/server.cpp.o" \
"CMakeFiles/server.dir/src/server_error.cpp.o" \
"CMakeFiles/server.dir/src/server_acceptor.cpp.o" \
"CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o" \
"CMakeFiles/server.dir/src/server_protected_clients.cpp.o" \
"CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o" \
"CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o" \
"CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o" \
"CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o" \
"CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/src/main.cpp.o
server: CMakeFiles/server.dir/src/client.cpp.o
server: CMakeFiles/server.dir/src/server.cpp.o
server: CMakeFiles/server.dir/src/server_error.cpp.o
server: CMakeFiles/server.dir/src/server_acceptor.cpp.o
server: CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o
server: CMakeFiles/server.dir/src/server_protected_clients.cpp.o
server: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o
server: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o
server: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o
server: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o
server: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o
server: CMakeFiles/server.dir/build.make
server: ../../common/libs/libyaml-cpp.a
server: ../libs/libBox2D.a
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grobles/tp-final-taller/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/main.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/client.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/server.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/server_error.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/server_acceptor.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/server_lobby_feeder.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/server_protected_clients.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/socket_error.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/thread.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/home/grobles/tp-final-taller/common/src/protocol_error.cpp.o.requires

.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/grobles/tp-final-taller/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grobles/tp-final-taller/server /home/grobles/tp-final-taller/server /home/grobles/tp-final-taller/server/build /home/grobles/tp-final-taller/server/build /home/grobles/tp-final-taller/server/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

