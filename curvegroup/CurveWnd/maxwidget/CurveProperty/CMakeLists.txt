cmake_minimum_required(VERSION 3.10.0)
project(CuvreProperty)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core widgets  REQUIRED)
enable_testing()

add_subdirectory(test)

file(GLOB qtpropertybrowser ./qtpropertybrowser/*)
file(GLOB src ./src/*)
add_library(CuvreProperty STATIC ${src} ${qtpropertybrowser})

target_include_directories(CuvreProperty PUBLIC ./src ./qtpropertybrowser)
target_link_libraries(CuvreProperty Qt5::Core Qt5::Widgets)

install(TARGETS ${PROJECT_NAME} ARCHIVE)
