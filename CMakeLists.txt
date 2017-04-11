cmake_minimum_required(VERSION 3.1)
project("lex")

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup()

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "2")
SET(VERSION_PATCH "0")

SET (CMAKE_BUILD_TYPE Debug) # 默认构建Debug模式
SET (CMAKE_CXX_STANDARD 11)

include_directories(include src third-party/cereal-1.1.2 ${CMAKE_CURRENT_BINARY_DIR})

#win32 use local flex include
if(WIN32)
	include_directories(./win32/flex/include)
endif()

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )


# bison and flex
if(UNIX)
    find_package(BISON REQUIRED)
    find_package(FLEX REQUIRED)
elseif(WIN32)
    #win32 use local bison and flex
    find_package(BISON PATHS ./win32/bison)
    find_package(FLEX PATHS ./win32/flex)
endif()

flex_target(SCANNER ./src/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp COMPILE_FLAGS -w)
bison_target(PARSER ./src/parser.y  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)



file(GLOB_RECURSE source_files
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    )

add_library(${PROJECT_NAME} ${source_files} ${BISON_PARSER_OUTPUTS} ${FLEX_SCANNER_OUTPUTS})

# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} SOVERSION ${VERSION_MAJOR})

if(build-doc)
	add_subdirectory(doc)
endif()
add_subdirectory(test)
