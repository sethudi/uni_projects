cmake_minimum_required(VERSION 3.14)

project(Question_three LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(Question_three
  main.cpp
  musicmodelview.h musicmodelview.cpp

  musicdelegate.h musicdelegate.cpp

)
target_link_libraries(Question_three Qt${QT_VERSION_MAJOR}::Core Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS Question_three
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
