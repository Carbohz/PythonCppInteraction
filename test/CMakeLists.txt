cmake_minimum_required(VERSION 3.12)

set(TEST_NAME dummy_lib_test)

set(SOURCES
    main.cpp
    test_sum.cpp
    )

add_executable(${TEST_NAME} ${SOURCES})

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)

target_link_libraries(${TEST_NAME} PRIVATE
    dummy_lib
    ${CONAN_LIBS}
)

#target_link_libraries(dummy_lib_test ${CONAN_LIBS})

add_test(NAME testlibtest
         COMMAND ${TEST_NAME}
)
