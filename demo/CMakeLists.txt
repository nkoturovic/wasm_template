add_executable(add_numbers add_numbers.cpp)
target_include_directories(add_numbers PRIVATE ../src) 
target_link_libraries(add_numbers LINK_PUBLIC mylib)
