cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#项目信息
project(xtionGrabber)

#查找当前目录下的所有源文件
#并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

#pcl
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#opencv
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

#指定生成目标
add_executable (xtionGrabber ${DIR_SRCS})
target_link_libraries (xtionGrabber ${PCL_LIBRARIES} ${OpenCV_LIBS})
