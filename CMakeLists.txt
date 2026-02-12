cmake_minimum_required(VERSION 3.16)
project(phpqt6_extension)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# Find PHP
find_program(PHP_CONFIG_EXECUTABLE NAMES php-config)
if(NOT PHP_CONFIG_EXECUTABLE)
    message(FATAL_ERROR "php-config not found. Please install PHP development package.")
endif()

execute_process(
    COMMAND ${PHP_CONFIG_EXECUTABLE} --include-dir
    OUTPUT_VARIABLE PHP_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND ${PHP_CONFIG_EXECUTABLE} --extension-dir
    OUTPUT_VARIABLE PHP_EXTENSION_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND ${PHP_CONFIG_EXECUTABLE} --includes
    OUTPUT_VARIABLE PHP_INCLUDES
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "PHP include dir: ${PHP_INCLUDE_DIR}")
message(STATUS "PHP extension dir: ${PHP_EXTENSION_DIR}")

# Source files
set(SOURCES
    src/php_qt6.cpp
    src/qapplication_binding.cpp
    src/qwidget_binding.cpp
    src/qpushbutton_binding.cpp
    src/qlabel_binding.cpp
    src/qmainwindow_binding.cpp
    src/qlineedit_binding.cpp
    src/qslider_binding.cpp
    src/qvboxlayout_binding.cpp
    src/qhboxlayout_binding.cpp
    src/qtabwidget_binding.cpp
    src/qtextedit_binding.cpp
    src/qcombobox_binding.cpp
    src/qcheckbox_binding.cpp
    src/qradiobutton_binding.cpp
    src/qspinbox_binding.cpp
    src/qmessagebox_binding.cpp
    src/qdialog_binding.cpp
    src/qfiledialog_binding.cpp
    src/qtablewidget_binding.cpp
    src/qtablewidgetitem_binding.cpp
    src/qsplitter_binding.cpp
    src/qscrollarea_binding.cpp
    src/qprogressbar_binding.cpp
    src/qgridlayout_binding.cpp
    src/qformlayout_binding.cpp
    src/qlistwidget_binding.cpp
    src/qtimer_binding.cpp
)

# Create the PHP extension
add_library(phpqt6 SHARED ${SOURCES})

target_include_directories(phpqt6 PRIVATE
    ${PHP_INCLUDE_DIR}
    ${PHP_INCLUDE_DIR}/main
    ${PHP_INCLUDE_DIR}/TSRM
    ${PHP_INCLUDE_DIR}/Zend
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(phpqt6
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)

# Add compile definitions for PHP extension
target_compile_definitions(phpqt6 PRIVATE
    COMPILE_DL_QT6
    ZEND_ENABLE_STATIC_TSRMLS_CACHE=1
)

# Set proper extension name and compilation flags
set_target_properties(phpqt6 PROPERTIES
    PREFIX ""
    OUTPUT_NAME "phpqt6"
    SUFFIX ".so"
    POSITION_INDEPENDENT_CODE ON
)

# Installation
install(TARGETS phpqt6
    LIBRARY DESTINATION ${PHP_EXTENSION_DIR}
)
