cmake_minimum_required (VERSION 3.8)

project ("Otus_7" VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}) 

add_executable(bulk otus_7.cpp) 

set_target_properties (
	bulk PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON	
)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost")
	return()
endif()

target_include_directories(
	bulk
	PRIVATE
	${PROJECT_SOURCE_DIR}
	${Boost_INCLUDE_DIRS}
)