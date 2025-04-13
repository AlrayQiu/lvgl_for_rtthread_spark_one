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

ioc配置仿照example.ioc