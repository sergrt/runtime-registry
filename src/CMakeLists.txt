cmake_minimum_required(VERSION 3.15)

project(runtime-registry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE
  main.cpp
)

set(HEADER
  example_dll_registry.h
  named_type.h
  runtime.h
  runtime_helpers.h
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})

add_library("example_dll" SHARED example_dll.cpp)
