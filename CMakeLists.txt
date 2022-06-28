cmake_minimum_required(VERSION 3.23)
project(backlight
    VERSION 0.0.5
    DESCRIPTION "Simple CLI backlight adjustment utility for Linux"
    LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include (GNUInstallDirs)
find_package(Threads REQUIRED)

option(STRICT_COMPILER_FLAGS "Use strict compiler flags" ON)
configure_file(src/version.hpp.in project_version.hpp)

add_executable( bli
        src/backlight_increment.cpp)
    set_target_properties(bli
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        VERSION ${PROJECT_VERSION})
    target_compile_definitions (bli
        PRIVATE VERSION=${PROJECT_VERSION})
    if (STRICT_COMPILER_FLAGS)
        target_compile_options( bli
            PRIVATE -Wall -Wextra -pedantic -Werror )
    endif(STRICT_COMPILER_FLAGS)
    #target_link_libraries( bli libluu)
    install(TARGETS bli
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_executable( bld
        src/backlight_decrement.cpp)
    set_target_properties(bld
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        VERSION ${PROJECT_VERSION})
    target_compile_definitions (bld
        PRIVATE VERSION=${PROJECT_VERSION})
    if (STRICT_COMPILER_FLAGS)
        target_compile_options( bld
            PRIVATE -Wall -Wextra -pedantic -Werror )
    endif(STRICT_COMPILER_FLAGS)

    #target_link_libraries(bld libluu)
    install(TARGETS bld
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_executable( bla
       src/backlight_absolute.cpp)
    set_target_properties(bla
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        VERSION ${PROJECT_VERSION})
    target_compile_definitions (bla
        PRIVATE VERSION=${PROJECT_VERSION})
    if (STRICT_COMPILER_FLAGS)
        target_compile_options( bla
            PRIVATE -Wall -Wextra -pedantic -Werror )
    endif (STRICT_COMPILER_FLAGS)

    #target_link_libraries(bla libluu)
    install(TARGETS bla
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_executable( bl-scanner 
       src/generate_backlight_config_file.cpp)
    set_target_properties( bl-scanner
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        VERSION ${PROJECT_VERSION})
        target_compile_definitions (bl-scanner
        PRIVATE VERSION=${PROJECT_VERSION})
    if (STRICT_COMPILER_FLAGS)
        target_compile_options( bl-scanner
            PRIVATE -Wall -Wextra -pedantic -Werror )
    endif( STRICT_COMPILER_FLAGS)

    #target_link_libraries(bl-scanner libluu)
    install(TARGETS bl-scanner
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)