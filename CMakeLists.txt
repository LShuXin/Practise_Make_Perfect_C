cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 99)

set(project_name Practise_Make_Perfect_C) ## rename your project here

project(${project_name} C)

include_directories(src)

add_library(${project_name}-lib
            src/a_test.h
            src/a_test.c
            src/headers.h
            src/basic_c_lang_knowledge/basic_c_lang_knowledge.h
            src/basic_c_lang_knowledge/basic_c_lang_knowledge.c
            src/file_operation/file_operation.h
            src/file_operation/file_operation.c
            )


add_executable(${project_name}-exe main.c)
#
target_link_libraries(${project_name}-exe ${project_name}-lib)
#add_dependencies(${project_name}-exe ${project_name}-lib)