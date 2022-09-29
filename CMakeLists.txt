cmake_minimum_required(VERSION 3.0.0)
project(CPratice VERSION 0.1.0)

aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(app ${SRC_SUB} ${SRC_CUR})
include_directories(inc)
