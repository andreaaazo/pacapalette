cmake_minimum_required(VERSION 4.2.3)

project(pacapalette)

# ---------------------
# Versioning
# ---------------------
set(pacapalette_VERSION_MAJOR 0)
set(pacapalette_VERSION_MINOR 1)
set(pacapalette_VERSION_PATCH 0)
set(pacapalette_VERSION_STATUS "-dev")

set(PROJECT_VERSION
    "${pacapalette_VERSION_MAJOR}.${pacapalette_VERSION_MINOR}.${pacapalette_VERSION_PATCH}${pacapalette_VERSION_STATUS}"
)

message(STATUS "${PROJECT_NAME} Project version: ${PROJECT_VERSION}")

# ---------------------
# Build Type
# ---------------------
if(NOT CMAKE_BUILD_TYPE)
    set(default_build_type "Debug")
    message(
        STATUS
        "Set the build type to `${default_build_type}` as none was specified."
    )
    set(CMAKE_BUILD_TYPE
        ${default_build_type}
        CACHE STRING
        "Choose the build type."
        FORCE
    )
    set_property(
        CACHE CMAKE_BUILD_TYPE
        PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo"
    )
endif()

message(STATUS "${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")

# ---------------------
# C++ Settings
# ---------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---------------------
# Warnings
# ---------------------
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ---------------------
# Find source files
# ---------------------
file(GLOB_RECURSE LIB_SOURCES "src/*.cpp")

# ---------------------
# Add Library
# ---------------------
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
