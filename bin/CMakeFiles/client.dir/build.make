# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/Arquivos_Client/Client.c.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/Arquivos_Client/Client.c.o: ../Arquivos_Client/Client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/client.dir/Arquivos_Client/Client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.dir/Arquivos_Client/Client.c.o   -c /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Arquivos_Client/Client.c

CMakeFiles/client.dir/Arquivos_Client/Client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/Arquivos_Client/Client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Arquivos_Client/Client.c > CMakeFiles/client.dir/Arquivos_Client/Client.c.i

CMakeFiles/client.dir/Arquivos_Client/Client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/Arquivos_Client/Client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Arquivos_Client/Client.c -o CMakeFiles/client.dir/Arquivos_Client/Client.c.s

CMakeFiles/client.dir/Arquivos_Client/Client.c.o.requires:

.PHONY : CMakeFiles/client.dir/Arquivos_Client/Client.c.o.requires

CMakeFiles/client.dir/Arquivos_Client/Client.c.o.provides: CMakeFiles/client.dir/Arquivos_Client/Client.c.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Arquivos_Client/Client.c.o.provides.build
.PHONY : CMakeFiles/client.dir/Arquivos_Client/Client.c.o.provides

CMakeFiles/client.dir/Arquivos_Client/Client.c.o.provides.build: CMakeFiles/client.dir/Arquivos_Client/Client.c.o


# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/Arquivos_Client/Client.c.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

bin/client: CMakeFiles/client.dir/Arquivos_Client/Client.c.o
bin/client: CMakeFiles/client.dir/build.make
bin/client: Lib/libLib.a
bin/client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: bin/client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/Arquivos_Client/Client.c.o.requires

.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

