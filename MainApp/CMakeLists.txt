cmake_minimum_required(VERSION 3.24)

set(PROJECT_NAME MainApp)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


set(QT_ROOT "C:/Qt/5.15.2")
set(QT_COMPILER "msvc2019_64")

set(RES_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/Res") 
set(DEST_DIR "$<TARGET_FILE_DIR:${PROJECT_NAME}>/alarmeffect/")

list (APPEND CMAKE_PREFIX_PATH
	"${QT_ROOT}/${QT_COMPILER}"
	"${QT_ROOT}/${QT_COMPILER}/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Multimedia)

# 5) 소스·헤더·리소스 파일 목록
set(SOURCES
    main.cpp

	# Core
	Core/TimeConfiguration.cpp
	Core/TimeConfiguration.h

	# Widgets
    QWidgets/mainwindow.cpp
    QWidgets/mainwindow.h
    QWidgets/mainwindow.ui
    QWidgets/TargetTimeDialog.cpp
    QWidgets/TargetTimeDialog.h
    QWidgets/TargetTimeDialog.ui

)

add_executable(${PROJECT_NAME} ${SOURCES})

if (WIN32)
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>
    )

    if (QT_VERSION_MAJOR EQUAL 5 AND TARGET Qt5::WinMain)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:Qt5::WinMain>)
    elseif(QT_VERSION_MAJOR EQUAL 6 AND TARGET Qt6::EntryPoint)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:Qt6::EntryPoint>)
    endif()
endif()

target_include_directories(${PROJECT_NAME} PRIVATE Core QWidgets)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Multimedia)

if(EXISTS "${RES_DIR}")
    add_custom_command(
        TARGET  ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${DEST_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${RES_DIR}" "${DEST_DIR}"
        COMMENT "Copying alarm sounds to ${DEST_DIR}")
else()
    message(WARNING "Resource directory ${RES_DIR} does not exist. Skipping copy.")
endif()

