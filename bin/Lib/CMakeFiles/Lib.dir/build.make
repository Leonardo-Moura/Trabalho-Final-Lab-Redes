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
include Lib/CMakeFiles/Lib.dir/depend.make

# Include the progress variables for this target.
include Lib/CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include Lib/CMakeFiles/Lib.dir/flags.make

Lib/CMakeFiles/Lib.dir/Comunicacao.c.o: Lib/CMakeFiles/Lib.dir/flags.make
Lib/CMakeFiles/Lib.dir/Comunicacao.c.o: ../Lib/Comunicacao.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Lib/CMakeFiles/Lib.dir/Comunicacao.c.o"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lib.dir/Comunicacao.c.o   -c /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Comunicacao.c

Lib/CMakeFiles/Lib.dir/Comunicacao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lib.dir/Comunicacao.c.i"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Comunicacao.c > CMakeFiles/Lib.dir/Comunicacao.c.i

Lib/CMakeFiles/Lib.dir/Comunicacao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lib.dir/Comunicacao.c.s"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Comunicacao.c -o CMakeFiles/Lib.dir/Comunicacao.c.s

Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.requires:

.PHONY : Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.requires

Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.provides: Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.requires
	$(MAKE) -f Lib/CMakeFiles/Lib.dir/build.make Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.provides.build
.PHONY : Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.provides

Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.provides.build: Lib/CMakeFiles/Lib.dir/Comunicacao.c.o


Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o: Lib/CMakeFiles/Lib.dir/flags.make
Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o: ../Lib/Manipulacao_de_Arquivos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o   -c /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Manipulacao_de_Arquivos.c

Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.i"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Manipulacao_de_Arquivos.c > CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.i

Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.s"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib/Manipulacao_de_Arquivos.c -o CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.s

Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.requires:

.PHONY : Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.requires

Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.provides: Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.requires
	$(MAKE) -f Lib/CMakeFiles/Lib.dir/build.make Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.provides.build
.PHONY : Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.provides

Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.provides.build: Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o


# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/Comunicacao.c.o" \
"CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

Lib/libLib.a: Lib/CMakeFiles/Lib.dir/Comunicacao.c.o
Lib/libLib.a: Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o
Lib/libLib.a: Lib/CMakeFiles/Lib.dir/build.make
Lib/libLib.a: Lib/CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libLib.a"
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean_target.cmake
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Lib/CMakeFiles/Lib.dir/build: Lib/libLib.a

.PHONY : Lib/CMakeFiles/Lib.dir/build

Lib/CMakeFiles/Lib.dir/requires: Lib/CMakeFiles/Lib.dir/Comunicacao.c.o.requires
Lib/CMakeFiles/Lib.dir/requires: Lib/CMakeFiles/Lib.dir/Manipulacao_de_Arquivos.c.o.requires

.PHONY : Lib/CMakeFiles/Lib.dir/requires

Lib/CMakeFiles/Lib.dir/clean:
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : Lib/CMakeFiles/Lib.dir/clean

Lib/CMakeFiles/Lib.dir/depend:
	cd /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/Lib /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib /home/leonardo/Documents/TrabRedes/Trabalho-Final-Lab-Redes/bin/Lib/CMakeFiles/Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Lib/CMakeFiles/Lib.dir/depend
