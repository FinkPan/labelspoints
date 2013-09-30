cmake_minimum_required(VERSION 2.8)

#项目名
project(labelspoints)

#包含include搜索			  
include_directories(${PROJECT_SOURCE_DIR}/include/labelspoints/)

#源文件
file(GLOB lib_srcs src/*.*)
#头文件
file(GLOB lib_hdrs include/labelspoints/*.*)
#单元测试
file(GLOB main_app main/*.*)

#Define a grouping for sources in the makefile.
source_group("INCLUDE" FILES ${lib_hdrs} )
source_group("SRC" FILES ${lib_srcs})


#生成静态库
add_library(labelspoints STATIC ${lib_hdrs} ${lib_srcs})
#生成可执行文件			  
add_executable(main_app ${main_app})
#设置依赖的动态库
target_link_libraries(main_app labelspoints)
