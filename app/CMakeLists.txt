add_executable(app main.cpp)

target_compile_features(app PRIVATE cxx_std_17)

# Include path for Python header files
include_directories(${PYTHON_INCLUDE_DIR})

# # Link against the Python shared library
# target_link_libraries(PythonCpp ${PYTHON_LIBRARY})

target_link_libraries(app PRIVATE dummy_lib ${PYTHON_LIBRARY})
