cmake_minimum_required(VERSION 3.5)

project(maxwidget)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core widgets  charts REQUIRED)

add_subdirectory(CurveProperty)
add_subdirectory(test)
file(GLOB SRC ./src/*)
add_library(maxwidget ${SRC} ${CurveProperty})

target_link_libraries(maxwidget  Qt5::Core Qt5::Widgets Qt5::Charts CuvreProperty)
target_include_directories(maxwidget PUBLIC  ./src)
enable_testing()
install(TARGETS ${PROJECT_NAME} ARCHIVE)
