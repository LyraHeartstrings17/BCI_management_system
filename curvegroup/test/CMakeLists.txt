cmake_minimum_required(VERSION 3.10.0)
project(curvegroup_test)
aux_source_directory(. src)
file(COPY ${CURVE_RES} DESTINATION ./res)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} curvegroup)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
