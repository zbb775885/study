CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(TEST)

SET(CMAKE_CXX_STANDARD 14)

ADD_EXECUTABLE(throw throw.cc)
ADD_EXECUTABLE(reload reload.cc)
ADD_EXECUTABLE(stl stl.cc)
ADD_EXECUTABLE(template template.cc)
ADD_EXECUTABLE(stl_vector stl_vector.cc)
ADD_EXECUTABLE(stl_algorithm stl_algorithm.cc)
ADD_EXECUTABLE(stl_iterator stl_iterator.cc)
