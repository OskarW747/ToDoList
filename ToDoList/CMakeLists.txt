# CMakeList.txt : CMake project for ToDoList, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ToDoList "src/Main.cpp" "src/Menus.cpp" "include/Menus.h" "include/Definitions.h" "include/Note.h" "src/Note.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ToDoList PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
