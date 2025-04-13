添加进项目cmake 

```
+=> add_subdirectory(lvgl)
```

```
# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
+=> spark_one_lvgl
    # Add user defined libraries
)
```

```
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
+=> lvgl/bsp/lcd.c
    # Add user sources here
)
```
添加进SysTick_Handler(void)
```
lv_tick_inc(1);

// 头文件"lv_hal_tick.h"
```

```

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

+=> add_link_options(-u _printf_float)

```

ioc配置仿照example.ioc