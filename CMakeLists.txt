cmake_minimum_required(VERSION 3.1)
project(concurrentes_tp1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 ")

set(SOURCE_FILES
    src/structures/EventHandler.h
    src/structures/Fifo.cpp
    src/structures/Fifo.h
    src/structures/FifoEscritura.cpp
    src/structures/FifoEscritura.h
    src/structures/FifoLectura.cpp
    src/structures/FifoLectura.h
    src/structures/Pipe.cpp
    src/structures/Pipe.h
    src/structures/LockFile.cpp
    src/structures/LockFile.h
    src/structures/MemoriaCompartida.h
    src/structures/SIGINT_Handler.h
    src/structures/SignalHandler.cpp
    src/structures/SignalHandler.h
    src/Cadete.cpp
    src/Cadete.h
    src/Cocinero.cpp
    src/Cocinero.h
    src/concurrentes_tp1.cpp
    src/GeneradorLlamados.cpp
    src/GeneradorLlamados.h
    src/Horno.cpp
    src/Horno.h
    src/Pizzeria.cpp
    src/Pizzeria.h
    src/Proceso.cpp
    src/Proceso.h
    src/Recepcionista.cpp
    src/Recepcionista.h
    src/Zappi.cpp
    src/Zappi.h)

add_executable(concurrentes_tp1 ${SOURCE_FILES})