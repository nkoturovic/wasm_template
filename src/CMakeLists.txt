add_executable(functions functions.cpp)

target_link_libraries(functions ${CMAKE_SOURCE_DIR}/mozjpeg/libs/libjpeg.a ${CMAKE_SOURCE_DIR}/mozjpeg/libs/libturbojpeg.a)
