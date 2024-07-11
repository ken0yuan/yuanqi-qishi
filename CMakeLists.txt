cmake_minimum_required(VERSION 3.5)
# 项目名称

# 使用C++ 11标准进行编译
set(CMAKE_PREFIX_PATH "E:/qqt/5.15.2/mingw81_64")

set(CMAKE_CXX_STANDARD 17)
# 要求代码必须遵守C++11标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#支持自定义信号，为Qt中的QObject子类自动生成moc文件*
set(CMAKE_AUTOMOC ON)
# 为Qt资源文件(.qrc)自动生成源文件
set(CMAKE_AUTORCC ON)
#为Qt设计器中生成的UI文件(.ui)自动生成头文件和源文件
set(CMAKE_AUTOUIC ON)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

enable_language(CXX)
#乱码问题处理
project(yuanqi_qishi)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
# 获取.h文件
file(GLOB headers 
${CMAKE_CURRENT_LIST_DIR}/../src/app/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/common/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/model/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/view/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/view/sink/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/sink/*.h
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/commands/*.h
)
#获取.cpp文件
file(GLOB soucers 
${CMAKE_CURRENT_LIST_DIR}/../src/main.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/app/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/common/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/model/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/view/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/view/sink/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/sink/*.cpp
${CMAKE_CURRENT_LIST_DIR}/../src/viewmodel/commands/*.cpp
)
#找第三方库
find_package(Qt5 COMPONENTS
Widgets 
Gui 
Core 
REQUIRED)
#文件链接生成可执行文件
add_executable(yuanqi_qishi  
            src/main.cpp
            src/app/app.cpp
            src/app/app.h
            src/common/role.h
            src/common/block.h
            src/common/map.h
            src/view/mainwindow.cpp
            src/view/mainwindow.h
            src/view/sink/mainwindowsink.cpp
            src/view/sink/mainwindowsink.h
            src/viewmodel/viewmodel.cpp
            src/viewmodel/viewmodel.h
            src/viewmodel/sink/viewmodelsink.cpp
            src/viewmodel/sink/viewmodelsink.h
            src/viewmodel/commands/move.cpp
            src/viewmodel/commands/move.h
            src/model/model.cpp
            src/model/model.h
            src/images.qrc
            src/common/parameter.h
            src/common/base.h
            src/view/mainwindow.ui
)

#链接第三方库
target_link_libraries(
    yuanqi_qishi 
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
)
# 生成可执行文件.exe
# install(TARGETS  DESTINATION ${CMAKE_CURRENT_LIST_DIR})

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

# 修改自定义命令以将 audio 插件目录复制到 cmake-build-debug 文件夹的根目录下
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${QT_INSTALL_PATH}/plugins/audio"
        "${CMAKE_BINARY_DIR}/audio")

# 创建自定义目标以确保上述命令在构建后执行
add_custom_target(copy_audio_plugins ALL
        COMMAND ${CMAKE_COMMAND} -E echo "Copying Qt audio plugins..."
        DEPENDS ${PROJECT_NAME})
