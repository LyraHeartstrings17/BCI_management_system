cmake_minimum_required(VERSION 3.5)

project(MAT LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

# 添加测试
add_subdirectory(test)
enable_testing()
file(GLOB SRC "src/*")
##TinyMAT包的位置设置
if(MSVC)
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        set(MATINCLUDE "matio/x86/release/include")
        file(GLOB MATLIB "matio/x86/release/lib/*.lib")
        file(GLOB MATDLL "matio/x86/release/bin/*.dll")
    else()
        set(MATINCLUDE "matio/x86/debug/include")
        file(GLOB MATLIB "matio/x86/debug/lib/*.lib")
        file(GLOB MATDLL "matio/x86/debug/bin/*.dll")
    endif()
endif()
set(MATDLL ${MATDLL} CACHE PATH "path of TinyMat")
add_library(MAT ${SRC})

target_link_libraries(MAT  Qt5::Core ${MATLIB})
target_include_directories(MAT PUBLIC "src" ${MATINCLUDE})
install(TARGETS ${PROJECT_NAME} ARCHIVE)
