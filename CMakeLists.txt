cmake_minimum_required(VERSION 3.0.0)
project(data-structures C CXX)

# include(CTest)
# enable_testing()

add_executable(${PROJECT_NAME} data-structures.cpp)
 
add_subdirectory("src/Singly Linked List")
add_subdirectory("src/Vector")


target_include_directories(${PROJECT_NAME} PUBLIC
    "src/Singly Linked List/"
    "src/Vector"
    )
    
target_link_libraries(
    ${PROJECT_NAME}
    singly-linked-list
    vector
    )


# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
