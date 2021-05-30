cmake_minimum_required(VERSION 3.12)

project(
  PythonCpp
  VERSION 0.1
  DESCRIPTION "Example for Python and Cpp interaction"
  LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# # Include path for Python header files
# include_directories(${PYTHON_INCLUDE_DIR})

# # Link against the Python shared library
# target_link_libraries(PythonCpp ${PYTHON_LIBRARY})

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

endif()

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)

add_subdirectory(test)

add_subdirectory(pybind11_lib)

add_subdirectory(proto)