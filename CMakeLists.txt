cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(RaylibGame)

option(USE_STATIC "Use static library" ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Налаштування для Android
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    set(CMAKE_ANDROID_NDK $ENV{ANDROID_NDK_HOME})
    set(CMAKE_SYSTEM_VERSION 21) # Мінімальна версія API
    set(CMAKE_ANDROID_ARCH_ABI "arm64-v8a") # Або "armeabi-v7a"
    set(CMAKE_ANDROID_STL_TYPE c++_static)
endif()

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

set(SOURCE_FILES
    ./src/Background/Background.cpp
    ./src/Food/Food.cpp
    ./src/Snake/Snake.cpp
    ./src/Menu/Menu.cpp
)

set(HEADER_FILES
    ./lib/Background.h
    ./lib/Food.h
    ./lib/Snake.h
    ./lib/Menu.h
)

# Для Android створюємо shared library замість executable
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    add_library(raylib_game SHARED src/main.cpp ${SOURCE_FILES})
else()
    add_executable(raylib_game src/main.cpp ${SOURCE_FILES})
endif()

# Включаємо директорії
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Підключення бібліотеки raylib
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    find_library(log-lib log) # Android-логування
    target_link_libraries(raylib_game PRIVATE raylib ${log-lib})
else()
    target_link_libraries(raylib_game PRIVATE raylib)
endif()
