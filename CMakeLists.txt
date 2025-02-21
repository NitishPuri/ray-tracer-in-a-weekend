cmake_minimum_required(VERSION 3.8)

set(NAME RayTracer)

message(STATUS "Using ${CMAKE_GENERATOR}")

project(${NAME} VERSION 0.0.1)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_compile_definitions(ROOT="${PROJECT_SOURCE_DIR}")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/ext
)
