cmake_minimum_required(VERSION 3.25)

project(deduplicator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(deduplicator ${APP_SOURCES})

target_include_directories(deduplicator PRIVATE include)

if(MSVC)
    target_compile_options(deduplicator PRIVATE /W4)
else()
    target_compile_options(deduplicator PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

    if(MINGW)
        target_link_libraries(deduplicator PRIVATE stdc++exp)
    endif()
endif()