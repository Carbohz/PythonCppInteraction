set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES_LIST "${SOURCES_DIR}/sum.cpp"
                 "${SOURCES_DIR}/sum.h"
                 "${SOURCES_DIR}/wrapped_sum.cpp"
                 "${SOURCES_DIR}/wrapped_sum.h"
                 )

set(MSVC_WARNINGS
/W4 # Baseline reasonable warnings
# /WX # Treat warnings as errors
/w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss of data
/w14254 # 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
/w14263 # 'function': member function does not override any base class virtual member function
/w14265 # 'classname': class has virtual functions, but destructor is not virtual instances of this class may not
        # be destructed correctly
/w14287 # 'operator': unsigned/negative constant mismatch
/we4289 # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside
        # the for-loop scope
/w14296 # 'operator': expression is always 'boolean_value'
/w14311 # 'variable': pointer truncation from 'type1' to 'type2'
/w14545 # expression before comma evaluates to a function which is missing an argument list
/w14546 # function call before comma missing argument list
/w14547 # 'operator': operator before comma has no effect; expected operator with side-effect
/w14549 # 'operator': operator before comma has no effect; did you intend 'operator'?
/w14555 # expression has no effect; expected expression with side- effect
/w14619 # pragma warning: there is no warning number 'number'
/w14640 # Enable warning on thread un-safe static member initialization
/w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
/w14905 # wide string literal cast to 'LPSTR'
/w14906 # string literal cast to 'LPWSTR'
/w14928 # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
/w15038 
/permissive- # standards conformance mode for MSVC compiler.
)           

# Make an automatic library - will be static or dynamic based on user setting
set(LIB_NAME dummy_lib)

add_library(${LIB_NAME} ${SOURCES_LIST})

set(PROJECT_WARNINGS ${MSVC_WARNINGS})
target_compile_options(${LIB_NAME} PRIVATE ${PROJECT_WARNINGS})
                 
# We need this directory, and users of our library will need it too
target_include_directories(${LIB_NAME} PUBLIC ${SOURCES_DIR})

# All users of this library will need at least C++17
target_compile_features(${LIB_NAME} PUBLIC cxx_std_17)

target_link_libraries(${LIB_NAME} ${CONAN_LIBS})

source_group(
  TREE "${SOURCES_DIR}"
  PREFIX "Source Files"
  FILES ${SOURCES_LIST})
