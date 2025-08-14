cmake_minimum_required(VERSION 3.16)
project(minecraftClone)

# Imposta lo standard C++ da utilizzare
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aggiungi il percorso delle directory dei file sorgente
# Utilizza GLOB per raccogliere automaticamente i file sorgente
file(GLOB SOURCES "src/core/*.cpp" "src/logmanager/*.cpp")
file(GLOB HEADERS "include/core/*.h" "include/logmanager/*.h")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/spdlog EXCLUDE_FROM_ALL)

# Crea l'eseguibile in base alla piattaforma
if(APPLE)
    add_executable(minecraftClone MACOSX_BUNDLE main.cpp ${SOURCES})
elseif(WIN32)
    add_executable(minecraftClone WIN32 main.cpp ${SOURCES})
else()
    add_executable(minecraftClone main.cpp ${SOURCES})
endif()

# Create a static library for glad
add_library(glad STATIC vendored/glad/src/glad.c)
target_include_directories(glad PUBLIC vendored/glad/include)

# Add the include directory to the target's include path
target_include_directories(minecraftClone PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    vendored/glad/include
)


find_package(OpenGL REQUIRED)

# Linka le librerie necessarie
target_link_libraries(minecraftClone PRIVATE SDL3::SDL3)
target_link_libraries(minecraftClone PRIVATE spdlog::spdlog)
target_link_libraries(minecraftClone PRIVATE glad)
target_link_libraries(minecraftClone PRIVATE OpenGL::GL)

# Copia le risorse nella directory di build in base alla piattaforma
if(APPLE)
    # Per macOS, le risorse vanno nel bundle. Questo comando viene eseguito dopo la compilazione.
    add_custom_command(TARGET minecraftClone POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/assets"
            "$<TARGET_BUNDLE_CONTENT_DIR:minecraftClone>/Resources/assets"
        )
else()
    # Per Windows e Linux, copia le risorse accanto all'eseguibile dopo la compilazione.
    add_custom_command(TARGET minecraftClone POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:minecraftClone>/assets"
        )
endif()
