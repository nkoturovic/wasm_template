add_executable(functions functions.cpp)

target_link_libraries(functions ${CMAKE_SOURCE_DIR}/mozjpeg-dist/libs/libjpeg.a ${CMAKE_SOURCE_DIR}/mozjpeg-dist/libs/libturbojpeg.a)
