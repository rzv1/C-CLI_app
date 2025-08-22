cmake_minimum_required(VERSION 3.31)
project(C_CLI_app C)

set(CMAKE_C_STANDARD 11)

add_executable(C_CLI_app main.c
        domain.c
        domain.h
        repo.c
        repo.h
        service.c
        service.h
        ui.c
        ui.h
        test.c
        test.h)
