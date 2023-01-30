CMAKE_MINIMUM_REQUIRED(VERSION 3.16.1)

PROJECT(dnn_test)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
	SET(CMAKE_CXX_STANDARD 14)
endif()

ADD_COMPILE_OPTIONS(-Wall -Wextra -Wpedantic)

# find dependencies
#FIND_PACKAGE()

INCLUDE_DIRECTORIES(include include/util/)

INCLUDE_DIRECTORIES(include ${PROJECT_SOURCE_DIR})

SET(SYS_ROOT ${CMAKE_SYSROOT})
MESSAGE("SYS_ROOT : " ${SYS_ROOT})

LINK_DIRECTORIES(${SYS_ROOT}/usr/lib/hbbpu/)

# Build dnn_node library
ADD_LIBRARY(${PROJECT_NAME} SHARED
	src/dnn_node.cpp
	src/dnn_node_impl.cpp
	src/util/image_proc.cpp
	src/util/output_parser/detection/nms.cpp
  	src/util/output_parser/utils.cpp
  	src/util/threads/threadpool.cpp
  	src/util/output_parser/detection/ptq_yolo3_darknet_output_parser.cpp
  	src/util/output_parser/detection/ptq_yolo2_output_parser.cpp
  	src/util/output_parser/detection/ptq_yolo5_output_parser.cpp
  	src/util/output_parser/detection/fasterrcnn_output_parser.cpp
  	src/util/output_parser/detection/ptq_efficientdet_output_parser.cpp
  	src/util/output_parser/detection/ptq_ssd_output_parser.cpp
  	src/util/output_parser/detection/fcos_output_parser.cpp
  	src/util/output_parser/classification/ptq_classification_output_parser.cpp
  	src/util/output_parser/segmentation/ptq_unet_output_parser.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	opencv_world
  	alog
  	hlog
  	easy_dnn
  	dnn
  	cnn_intf
  	ion
  	hbrt_bernoulli_aarch64	
)


