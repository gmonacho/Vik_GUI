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
CMAKE_SOURCE_DIR = /home/gal/101/Vik_Wrap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gal/101/Vik_Wrap/build

# Include any dependencies generated for this target.
include CMakeFiles/Vik_Wrap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vik_Wrap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vik_Wrap.dir/flags.make

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o: ../src/Init.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o -c /home/gal/101/Vik_Wrap/src/Init.cpp

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Init.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Init.cpp > CMakeFiles/Vik_Wrap.dir/src/Init.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Init.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Init.cpp -o CMakeFiles/Vik_Wrap.dir/src/Init.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o -c /home/gal/101/Vik_Wrap/src/Window.cpp

CMakeFiles/Vik_Wrap.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Window.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Window.cpp > CMakeFiles/Vik_Wrap.dir/src/Window.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Window.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Window.cpp -o CMakeFiles/Vik_Wrap.dir/src/Window.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o -c /home/gal/101/Vik_Wrap/src/Renderer.cpp

CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Renderer.cpp > CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Renderer.cpp -o CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o: ../src/Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o -c /home/gal/101/Vik_Wrap/src/Event.cpp

CMakeFiles/Vik_Wrap.dir/src/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Event.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Event.cpp > CMakeFiles/Vik_Wrap.dir/src/Event.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Event.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Event.cpp -o CMakeFiles/Vik_Wrap.dir/src/Event.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o: ../src/Rect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o -c /home/gal/101/Vik_Wrap/src/Rect.cpp

CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Rect.cpp > CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Rect.cpp -o CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o -c /home/gal/101/Vik_Wrap/src/Point.cpp

CMakeFiles/Vik_Wrap.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Point.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Point.cpp > CMakeFiles/Vik_Wrap.dir/src/Point.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Point.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Point.cpp -o CMakeFiles/Vik_Wrap.dir/src/Point.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o: ../src/Line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o -c /home/gal/101/Vik_Wrap/src/Line.cpp

CMakeFiles/Vik_Wrap.dir/src/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Line.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Line.cpp > CMakeFiles/Vik_Wrap.dir/src/Line.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Line.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Line.cpp -o CMakeFiles/Vik_Wrap.dir/src/Line.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o: ../src/Font.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o -c /home/gal/101/Vik_Wrap/src/Font.cpp

CMakeFiles/Vik_Wrap.dir/src/Font.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Font.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Font.cpp > CMakeFiles/Vik_Wrap.dir/src/Font.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Font.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Font.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Font.cpp -o CMakeFiles/Vik_Wrap.dir/src/Font.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o: ../src/Exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o -c /home/gal/101/Vik_Wrap/src/Exception.cpp

CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Exception.cpp > CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Exception.cpp -o CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o


CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o: CMakeFiles/Vik_Wrap.dir/flags.make
CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o -c /home/gal/101/Vik_Wrap/src/Texture.cpp

CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/101/Vik_Wrap/src/Texture.cpp > CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.i

CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/101/Vik_Wrap/src/Texture.cpp -o CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.s

CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.requires:

.PHONY : CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.requires

CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.provides: CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/Vik_Wrap.dir/build.make CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.provides

CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.provides.build: CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o


# Object files for target Vik_Wrap
Vik_Wrap_OBJECTS = \
"CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o" \
"CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o"

# External object files for target Vik_Wrap
Vik_Wrap_EXTERNAL_OBJECTS =

libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/build.make
libVik_Wrap.so: CMakeFiles/Vik_Wrap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gal/101/Vik_Wrap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared module libVik_Wrap.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vik_Wrap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vik_Wrap.dir/build: libVik_Wrap.so

.PHONY : CMakeFiles/Vik_Wrap.dir/build

CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Init.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Window.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Renderer.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Event.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Rect.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Point.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Line.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Font.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Exception.cpp.o.requires
CMakeFiles/Vik_Wrap.dir/requires: CMakeFiles/Vik_Wrap.dir/src/Texture.cpp.o.requires

.PHONY : CMakeFiles/Vik_Wrap.dir/requires

CMakeFiles/Vik_Wrap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vik_Wrap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vik_Wrap.dir/clean

CMakeFiles/Vik_Wrap.dir/depend:
	cd /home/gal/101/Vik_Wrap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gal/101/Vik_Wrap /home/gal/101/Vik_Wrap /home/gal/101/Vik_Wrap/build /home/gal/101/Vik_Wrap/build /home/gal/101/Vik_Wrap/build/CMakeFiles/Vik_Wrap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vik_Wrap.dir/depend

