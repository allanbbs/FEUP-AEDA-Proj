cmake_minimum_required(VERSION 3.15)
project(AEDA_Proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDA_Proj1 main.cpp Source/Empresa.cpp Source/Camiao.cpp Header/Camiao.h Source/Clientes.cpp Source/Servicos.cpp Source/Local.cpp Source/Errors.cpp Source/TaxTable.cpp)