cmake_minimum_required(VERSION 3.5)

project(our_project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS PrintSupport REQUIRED)


set (SOURCE
    ./source/mainwindow.cpp
    ./source/main.cpp
    ./source/Forward_fourier_decomposer.cpp
    ./source/Signal.cpp
    ./qcustomplot.cpp
    ./source/graph.cpp
    ./source/oscilloscope.cpp
    ./source/main_controller.cpp
    ./source/block.cpp
    ./source/generator.cpp
    ./source/block_low_pass_filter.cpp
    ./source/Forward_fourier_decomposer.cpp
    ./source/Reverse_fourier_decomposer.cpp
    ./source/Filters/High_pass_filter.cpp
    ./source/Filters/Low_pass_filter.cpp
    ./source/widget.cpp
    ./source/form.cpp
    ./source/harmony_oscilloscope.cpp

    ./source/transformer.cpp
    #./source/cambiner.cpp

    source/logic_of_fronted/mylistwidget.cpp
    source/logic_of_fronted/CustomFrame.cpp
    source/logic_of_fronted/MoveItem.cpp
    source/logic_of_fronted/my_grpah_view.cpp
    ./FrontedObjects/FrontedOscilloscope.cpp
    source/block_connector.cpp
    FrontedObjects/VirualLabel.cpp
    FrontedObjects/DialogWindow.cpp
    FrontedObjects/FrontedGenerator.cpp
    headers/logic_of_fronted/graphmap.cpp
    FrontedObjects/FrontedHighPassFilter.cpp








    )
set (HEADERS
    ./headers/mainwindow.h
    ./headers/Forward_fourier_decomposer.h
    ./headers/Reverse_fourier_decomposer.h
    ./headers/Signal.h
    ./qcustomplot.h
    ./headers/graph.h
    ./headers/oscilloscope.h
    ./headers/main_controller.h
    ./headers/block.h
    ./headers/generator.h
    ./headers/block_low_pass_filter.h
    ./headers/Forward_fourier_decomposer.h
    ./headers/Filters/High_pass_filter.h
    ./headers/Filters/Low_pass_filter.h
    ./headers/widget.h
    ./headers/form.h
    ./headers/harmony_oscilloscope.h

    ./headers/transformer.h
    #./headers/spline.h
    #./headers/cambiner.h

    headers/logic_of_fronted/mylistwidget.h
    headers/logic_of_fronted/CustomFrame.h
    headers/logic_of_fronted/MoveItem.h
    headers/logic_of_fronted/my_grpah_view.h
    ./FrontedObjects/FrontedOscilloscope.h
    FrontedObjects/VirualLabel.h
    FrontedObjects/DialogWindow.h
    FrontedObjects/FrontedGenerator.h
    headers/logic_of_fronted/graphmap.h
    FrontedObjects/FrontedHighPassFilter.h








    )

set(PROJECT_SOURCES
        mainwindow.ui
        ./source/graph.ui
        ./source/widget.ui
        ./source/form.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
#Define properties for Android with Qt 5 after find_package() calls as:
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled
            ${PROJECT_SOURCES} ${SOURCE} ${HEADERS}
        )
    endif()
endif()

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

#set_target_properties(untitled PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
