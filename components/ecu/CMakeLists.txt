cmake_minimum_required(VERSION 3.17)


set(HEADERS
        include/ECU/Interface/IGpioContentReader.hpp
        include/ECU/Interface/KLineNetworkConnector.hpp
        include/ECU/Interface/NetworkConnector.hpp
        include/ECU/Interface/UartNetworkConnector.hpp
        include/ECU/exception.hpp
        include/ECU/GpioContentReader.h
        include/ECU/HondaECU.hpp
        include/ECU/KLineNetworkConnector.hpp
        include/ECU/UartNetworkConnector.hpp)

set(SOURCES
        src/GpioContentReader.cpp
        src/UartNetworkConnector.cpp
        src/HondaECU.cpp
        src/KLineNetworkConnector.cpp
    ${HEADERS})

set(COMPONENTS
        common
        driver
        executor)

idf_component_register(SRCS ${SOURCES} INCLUDE_DIRS include REQUIRES ${COMPONENTS})
