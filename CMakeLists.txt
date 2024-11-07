cmake_minimum_required(VERSION 3.28)
project(busSchedule)

set(CMAKE_CXX_STANDARD 17)

add_executable(busSchedule main.cpp
        bus_schedule.cpp
        bus_schedule.h
        bus_schedule_manager.cpp
        bus_schedule_manager.h
)
