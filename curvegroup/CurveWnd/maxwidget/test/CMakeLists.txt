cmake_minimum_required(VERSION 3.10.0)
project(libtest)
aux_source_directory(. src)
add_executable(libtest ${src})

target_link_libraries(libtest maxwidget)
