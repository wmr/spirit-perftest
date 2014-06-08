cmake_minimum_required (VERSION 2.8)
project (spirit_perftest)
	set(CMAKE_BUILD_TYPE Release)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 -O3")
	include_directories("/opt/local/include")
	add_executable(spirit_parser spiritIntParser.cc)
	add_executable(spiritless_parser spiritlessIntParser.cc)

