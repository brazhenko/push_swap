cmake_minimum_required(VERSION 3.1)
project(push C)

set(CMAKE_C_STANDARD 99)

set(PUSH_SWAP_LIB_SRC
		push_swap_lib/pstack.c
		push_swap_lib/game_wrapper.c
		push_swap_lib/game_wrapper2.c
		push_swap_lib/game_wrapper3.c
		push_swap_lib/game_wrapper4.c
		push_swap_lib/parse_argv.c
		push_swap_lib/error.c
		utilities_lib/memcpy.c
		push_swap_lib/game_wrapper5.c
		push_swap_lib/game_wrapper6.c)

set(PUSH_SWAP_LIB_HEAD
		push_swap_lib/pstack.h
		)

add_library(push_swap_lib
STATIC

${PUSH_SWAP_LIB_SRC}
${PUSH_SWAP_LIB_HEAD})

set(UTILITIES_SRC
		utilities_lib/ft_atoi.c
		utilities_lib/ft_itoa.c
		utilities_lib/strsplitchrset.c
		utilities_lib/xmalloc.c
		utilities_lib/strsub.c
		utilities_lib/strncpy.c
		utilities_lib/strnew.c
		utilities_lib/memset.c
		utilities_lib/charptrptrdel.c
		utilities_lib/strcmp.c
		utilities_lib/strncmp.c
		utilities_lib/max.c)

set(UTILITIES_INC
		utilities_lib/utilities.h
		)

add_library(utlib STATIC ${UTILITIES_SRC} ${UTILITIES_INC})

include_directories(utilities_lib)

#add_executable(${PROJECT_NAME}
#		push/sorter.h
#		push/main.c
#		push/fill_one.c
#		push/sort.c
#		push/accessories.c
#		push/calc_shortest_way_len.c
#		push/process_put.c)

add_executable(checker1 check/main.c check/error.c  check/checker.h)

#target_link_libraries(${PROJECT_NAME} push_swap_lib utlib)
target_link_libraries(checker1 push_swap_lib utlib)