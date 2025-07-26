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

# Crea l'eseguibile
add_executable(minecraftClone MACOSX_BUNDLE main.cpp ${SOURCES})

# Add the include directory to the target's include path
target_include_directories(minecraftClone PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Linka le librerie necessarie
target_link_libraries(minecraftClone PRIVATE SDL3::SDL3)
target_link_libraries(minecraftClone PRIVATE spdlog::spdlog)

# Copia le risorse nella directory di build
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/Release/minecraftClone.app/Contents/Resources)
