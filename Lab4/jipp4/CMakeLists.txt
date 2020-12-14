cmake_minimum_required( VERSION 3.0 )
project( jipp4 )

# include
include_directories( ./include  )

# target
add_executable( jipp4 ./tests/jipp4.cpp )