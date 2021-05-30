add_definitions(-D_WIN32_WINNT=0x600)
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
#find_package(gRPC CONFIG REQUIRED)

set (SOURCES
    main.cpp)

set (GENERATED_SOURCES
    file.grpc.pb.cc
    file.pb.cc)

add_executable(gRPC_example
    ${SOURCES}
    ${GENERATED_SOURCES}
    )

# target_link_libraries(gRPC_example PRIVATE dummy_lib)

target_link_libraries(gRPC_example PRIVATE
    dummy_lib
    ${CONAN_LIBS}
)

# target_link_libraries(gRPC_example PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts gRPC::grpc_plugin_support gRPC::grpc++_reflection)
# target_link_libraries(gRPC_example PRIVATE c-ares::cares)
# target_link_libraries(gRPC_example PRIVATE Shlwapi)