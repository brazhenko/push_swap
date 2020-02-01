cmake_minimum_required(VERSION 3.15)
project(push C)

set(CMAKE_C_STANDARD 99)

set(PUSH_SWAP_LIB_SRC push_swap_lib/pushswap.c push_swap_lib/game_wrapper.c)

set(PUSH_SWAP_LIB_HEAD push_swap_lib/pushswap.h)

add_library(push_swap_lib STATIC  ${PUSH_SWAP_LIB_SRC} ${PUSH_SWAP_LIB_HEAD})

#add_executable(${PROJECT_NAME} main.c)
add_executable(${PROJECT_NAME} checker/main.c)

target_link_libraries(${PROJECT_NAME} push_swap_lib)