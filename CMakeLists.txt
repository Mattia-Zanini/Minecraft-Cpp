cmake_minimum_required(VERSION 3.24)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "15.0")
endif()

# Imposta il triplet statico di default per Windows su vcpkg se non specificato
if(WIN32 AND NOT DEFINED VCPKG_TARGET_TRIPLET)
    set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "vcpkg target triplet")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_NO_SYSTEM_FROM_IMPORTED ON)

project(MinecraftCpp VERSION 0.1 LANGUAGES C CXX)

# Dipendenze gestite tramite vcpkg
find_package(SDL3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG QUIET)
find_package(OpenGL REQUIRED)

# Raccoglie automaticamente i file sorgente e header del progetto
file(GLOB SOURCES CONFIGURE_DEPENDS
    "main.cpp"
    "src/*.cpp"
    "src/*/*.cpp"
)

file(GLOB HEADERS CONFIGURE_DEPENDS
    "include/*.h"
    "include/*.hpp"
    "include/*/*.h"
    "include/*/*.hpp"
)

# Crea l'eseguibile in base alla piattaforma
if(APPLE)
    add_executable(minecraftClone MACOSX_BUNDLE ${SOURCES} ${HEADERS})
elseif(WIN32)
    add_executable(minecraftClone WIN32 ${SOURCES} ${HEADERS})
else()
    add_executable(minecraftClone ${SOURCES} ${HEADERS})
endif()

# Opzioni di compilazione per MSVC
if(MSVC)
    target_compile_options(minecraftClone PRIVATE /std:c++latest)
endif()

# Directory di inclusione
target_include_directories(minecraftClone PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link delle librerie statiche
target_link_libraries(minecraftClone PRIVATE
    SDL3::SDL3
    spdlog::spdlog
    fmt::fmt
    OpenGL::GL
)

if(TARGET glad::glad)
    target_link_libraries(minecraftClone PRIVATE glad::glad)
elseif(TARGET glad)
    target_link_libraries(minecraftClone PRIVATE glad)
endif()

if(TARGET glm::glm)
    target_link_libraries(minecraftClone PRIVATE glm::glm)
endif()

# Su macOS, se SDL3 è linkato staticamente, linka i framework di sistema necessari
if(APPLE)
    find_library(COCOA_FRAMEWORK Cocoa REQUIRED)
    find_library(IOKIT_FRAMEWORK IOKit REQUIRED)
    find_library(COREVIDEO_FRAMEWORK CoreVideo REQUIRED)
    find_library(COREAUDIO_FRAMEWORK CoreAudio REQUIRED)
    find_library(AUDIOTOOLBOX_FRAMEWORK AudioToolbox REQUIRED)
    find_library(METAL_FRAMEWORK Metal REQUIRED)
    target_link_libraries(minecraftClone PRIVATE
        ${COCOA_FRAMEWORK}
        ${IOKIT_FRAMEWORK}
        ${COREVIDEO_FRAMEWORK}
        ${COREAUDIO_FRAMEWORK}
        ${AUDIOTOOLBOX_FRAMEWORK}
        ${METAL_FRAMEWORK}
    )
endif()

# Copia le risorse (assets) nella directory di output/bundle
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/assets")
    if(APPLE)
        # Per macOS, le risorse vanno nel bundle
        add_custom_command(TARGET minecraftClone POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/assets"
                "$<TARGET_BUNDLE_CONTENT_DIR:minecraftClone>/Resources/assets"
            COMMENT "Copia delle risorse (assets) nel bundle macOS..."
        )
    else()
        # Per Windows e Linux, copia le risorse accanto all'eseguibile
        add_custom_command(TARGET minecraftClone POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/assets"
                "$<TARGET_FILE_DIR:minecraftClone>/assets"
            COMMENT "Copia delle risorse (assets) nella directory di build..."
        )
    endif()
endif()
