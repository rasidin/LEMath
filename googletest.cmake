cmake_minimum_required(VERSION 3.1)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest-download
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG master
				SOURCE_DIR ${CMAKE_BINARY_DIR}/googletest-src
				BINARY_DIR ${CMAKE_BINARY_DIR}/googltest-build
                UPDATE_DISCONNECTED 1
)
