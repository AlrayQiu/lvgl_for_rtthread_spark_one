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

ioc配置仿照example.ioc