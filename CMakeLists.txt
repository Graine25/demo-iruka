
# iruka - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(iruka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(IRUKA_SOURCES
    src/main.cpp
    src/hooks.cpp
)

if(WIN32)
    add_executable(iruka WIN32 ${IRUKA_SOURCES})
else()
    add_executable(iruka ${IRUKA_SOURCES})
endif()

rexglue_setup_target(iruka GPU_PLUGINS xenos)

# ReXGlue loads <executable-name>.toml from the executable directory. Keep the
# tracked runtime configuration separate from iruka_config.toml, which is used
# exclusively by codegen through iruka_manifest.toml.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/iruka.toml"
    "${CMAKE_CURRENT_BINARY_DIR}/iruka.toml"
    COPYONLY
)

install(TARGETS iruka RUNTIME DESTINATION . BUNDLE DESTINATION .)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/iruka.toml" DESTINATION .)
