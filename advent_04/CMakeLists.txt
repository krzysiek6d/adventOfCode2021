get_filename_component(exec_name ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" exec_name ${exec_name})
set(test_name ${exec_name}_test)

set(sources solution.cpp)
set(tests tests.cpp)

add_executable(${exec_name}
    main.cpp
    ${sources}
)

add_executable(${test_name} 
    ${sources}
    ${tests}
)
target_link_libraries(${test_name} gtest_main gmock)
add_test(${test_name} ${test_name})