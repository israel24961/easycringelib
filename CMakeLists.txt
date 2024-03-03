cmake_minimum_required(VERSION 3.27) # setting this is required
project(easycringelib VERSION 1.0.0 DESCRIPTION "Personal library for common C structs and types")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -O3 ")

file(GLOB_RECURSE sources  src/easycringelib.h)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library( ${PROJECT_NAME} SHARED  ${sources} )

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER src/easycringelib.h
    )

target_include_directories(${PROJECT_NAME} PUBLIC src)



###############################################################################
## dependencies ###############################################################
###############################################################################
install( TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
