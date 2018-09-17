cmake_minimum_required(VERSION 2.8)
MESSAGE( STATUS "Running CMake for BuildMetaInfo module")

file(MAKE_DIRECTORY  ${PROJECT_BINARY_DIR}/BuildMetaInfo/generated)

add_custom_target(runPythonGenerator ALL
	DEPENDS alwaysRunGenerateCommand
)

add_custom_command(OUTPUT alwaysRunGenerateCommand # note output never actually created: ensures cmd always runs
	COMMENT "generating meta build info definitions header using python script" 
	WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
	DEPENDS ${CMAKE_CURRENT_LIST_DIR}/build_meta_info.py
	COMMAND python ${CMAKE_CURRENT_LIST_DIR}/build_meta_info.py --target_generation_dir ${PROJECT_BINARY_DIR}/BuildMetaInfo/generated --toolkit_libs '${OPCUA_TOOLKIT_LIBS}'
)

file(GLOB BUILD_META_INFO_SRCS src/*.cpp include/*.h)

include_directories(include)

add_library (BuildMetaInfo OBJECT ${BUILD_META_INFO_SRCS} )

message(STATUS "building version info source files [${BUILD_META_INFO_SRCS}]")

add_dependencies (BuildMetaInfo
	runPythonGenerator
	${PROJECT_BINARY_DIR}/BuildMetaInfo/generated/BuildMetaInfoGenerated.h
)