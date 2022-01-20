cmake_minimum_required(VERSION 2.8.11)

project(helloworld)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(STATIC_QT "Use static Qt6 libraries" ON)

if(STATIC_QT)
    set(LINKER_FLAGS -static -static-libstdc++ -static-libgcc)
    find_package(Qt6Core REQUIRED)
    set(QT_PREFIX StaticQt6)
else()
    set(QT_PREFIX Qt6)
endif()

set(QT6_PKGS Widgets)

set(QT6_LIBS "")

foreach(pkg ${QT6_PKGS})
    find_package(${QT_PREFIX}${pkg} REQUIRED)
    list(APPEND QT6_LIBS ${QT_PREFIX}::${pkg})
endforeach()

# Turn on automatic invocation of the MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# There may be a way to tell up front if Qt6 is going to be found, but I haven't found
# a foolproof way to do it yet, so settle for the default error message for now.
#if(NOT CMAKE_PREFIX_PATH AND NOT Qt6Widgets_DIR)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, so find_package may not work. Set the CMAKE_PREFIX_PATH "
#            "environment variable to the install prefix of Qt 5, either on the command line as "
#            "-DCMAKE_PREFIX_PATH=\"path/to/Qt6/lib/cmake\" or with set(CMAKE_PREFIX_PATH path/to/Qt6/lib/cmake)")
#endif(NOT CMAKE_PREFIX_PATH AND NOT Qt6Widgets_DIR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra --pedantic")

if(WIN32)
    set(EXE_TYPE WIN32)
endif()

# Tell CMake to create the helloworld executable
add_executable(helloworld ${EXE_TYPE} main.cpp mainwindow.cpp mainwindow.ui resources.qrc)

# Add the Qt6 Widgets for linking
target_link_libraries(helloworld ${LINKER_FLAGS} ${QT6_LIBS})

if(STATIC_QT)
    set_target_properties(helloworld PROPERTIES
        LINK_SEARCH_START_STATIC ON
        LINK_SEARCH_END_STATIC ON)
endif()
