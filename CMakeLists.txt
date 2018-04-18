cmake_minimum_required(VERSION 3.9)
project(OS_P1)

set(CMAKE_CXX_STANDARD 11)

add_executable(OS_P1
        "Docs/New Text Document.txt"
        Docs/Programs.txt
        include/ALU.h
        include/CPU.h
        include/CpuMem.h
        include/CU.h
        include/Dispatcher.h
        include/Driver.h
        include/FCFS_Scheduler.h
        include/HDD.h
        include/IScheduler.h
        include/Loader.h
        include/m32.h
        include/Motherboard.h
        include/PCB.h
        include/PriorityScheduler.h
        include/ProcessPool.h
        include/RAM.h
        src/ALU.cpp
        src/CPU.cpp
        src/CpuMem.cpp
        src/CU.cpp
        src/Dispatcher.cpp
        src/Driver.cpp
        src/FCFS_Scheduler.cpp
        src/HDD.cpp
        src/IScheduler.cpp
        src/Loader.cpp
        src/m32.cpp
        src/Motherboard.cpp
        src/PCB.cpp
        src/PriorityScheduler.cpp
        src/ProcessPool.cpp
        src/RAM.cpp
        src/tester.cpp
        .gitattributes
        .gitignore)

include_directories(include)
