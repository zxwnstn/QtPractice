cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(Practice LANGUAGES CXX)

add_compile_options(/std:c++17)

#Setup Qt5 for msvc2017 x64
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "../vendor/Qt5_MSVC")
set(QTDIR "../Qt5_MSVC/")
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

#ui
set(project_ui
    src/MainWindow/mainwindow.ui
    src/MyWidget/MyFirstWidget.ui
	src/ex10/Splitters.ui    
)

#header
set(project_headers
    src/pch.h
    src/MainWindow/mainwindow.h
    src/MyWidget/MyFirstWidget.h
    src/MyWidget/MySecondWidget.h
	src/ex10/Splitters.h
)

#cpp
set(project_sources 
    src/pch.cpp
    src/main.cpp
    src/MainWindow/mainwindow.cpp
    src/MyWidget/MyFirstWidget.cpp
    src/MyWidget/MySecondWidget.cpp
	src/ex10/Splitters.cpp
)

#qrc
set(project_qrc
    files/MyResources.qrc
)

#QtAuto Generate - moc, ui
qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(
	${PROJECT_NAME} 
	${project_headers} 
	${project_sources}
	${project_qrc} 
	${project_sources_moc} 
	${project_headers_wrapped} 
)

#precompile header
target_precompile_headers(
	${PROJECT_NAME} 
	PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h"
)

#include dir
target_include_directories(
	${PROJECT_NAME} 
	PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#library
target_link_libraries(
	${PROJECT_NAME}
    PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)