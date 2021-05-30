mkdir build && cd build
conan install .. -s build_type=Release
set PROTO_BIN="C:/.conan/52b9e7/1/bin/protoc.exe"
set GRPC_CPP_PLUGIN="C:/.conan/514a8b/1/bin/grpc_cpp_plugin.exe"
set SRC_DIR=D:/CppProjects/PythonCpp/proto
set DST_DIR=D:/CppProjects/PythonCpp/proto
set PROTO_FILE_DIR=D:/CppProjects/PythonCpp/proto
set PYTHON_DST_DIR=D:/CppProjects/PythonCpp/python_src
%PROTO_BIN% -I=%SRC_DIR% --grpc_out=%DST_DIR% --plugin=protoc-gen-grpc=%GRPC_CPP_PLUGIN% %SRC_DIR%/file.proto
%PROTO_BIN% -I=%SRC_DIR% --cpp_out=%DST_DIR% %SRC_DIR%/file.proto
python -m grpc_tools.protoc -I%PROTO_FILE_DIR% --python_out=%PYTHON_DST_DIR% --grpc_python_out=%PYTHON_DST_DIR% %PROTO_FILE_DIR%/file.proto
cmake .. -DPYTHON_INCLUDE_DIR="C:/Python395/include" -DPYTHON_LIBRARY="C:/Python395/libs/python39.lib" -DCMAKE_TOOLCHAIN_FILE="C:/.conan/514a8b/1/lib/cmake/grpc_cpp_plugin.cmake"
cmake --build . --config Release
cd ..
