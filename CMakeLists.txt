set(target spark_one_lvgl)

add_library(${target} STATIC)

target_compile_definitions(${target} PUBLIC "-DLV_CONF_INCLUDE_SIMPLE")
target_compile_definitions(${target} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")


target_include_directories(${target} PUBLIC ./)
target_include_directories(${target} PUBLIC ./bsp)
target_include_directories(${target} PUBLIC ./src)
target_include_directories(${target} PUBLIC ./src/core)
target_include_directories(${target} PUBLIC ./src/draw)
target_include_directories(${target} PUBLIC ./src/extra)
target_include_directories(${target} PUBLIC ./src/font)
target_include_directories(${target} PUBLIC ./src/gpu)
target_include_directories(${target} PUBLIC ./src/hal)
target_include_directories(${target} PUBLIC ./src/misc)
target_include_directories(${target} PUBLIC ./src/widgets)

# app include
target_include_directories(${target} PUBLIC ./examples)

# app src
file(GLOB_RECURSE src_lvgl_app examples/*.c)
file(GLOB_RECURSE src_bsp bsp/*.c)

file(GLOB_RECURSE src_lvgl src/*.c)

target_sources(${target} PRIVATE
    ${src_lvgl}
    ${src_lvgl_app}
)