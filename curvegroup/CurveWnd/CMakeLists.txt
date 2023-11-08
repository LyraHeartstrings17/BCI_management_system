cmake_minimum_required(VERSION 3.10.0)
project(curvewnd)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#添加测试
enable_testing()
add_subdirectory(maxwidget)
add_subdirectory(test)
#获取源文件
file(GLOB SRC ./src/*)

find_package(Qt5 COMPONENTS core widgets charts REQUIRED)
add_library(curvewnd STATIC ${SRC})
target_include_directories(curvewnd PUBLIC "./src/")
target_link_libraries(curvewnd Qt5::Core Qt5::Widgets Qt5::Charts maxwidget)

install(TARGETS ${PROJECT_NAME} ARCHIVE)
