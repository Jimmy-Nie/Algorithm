INCLUDE_DIRECTORIES(
        ./
        )

FILE(GLOB_RECURSE Astar_SRCs
        "*.c*"
        "*.h*"
        )

find_package(OpenCV REQUIRED)

#Generate the lib and executable file
SET(BIN_NAME Astar)
ADD_EXECUTABLE(${BIN_NAME} ${Astar_SRCs})
TARGET_LINK_LIBRARIES(${BIN_NAME} PUBLIC pthread dl ${OpenCV_LIBS})
message(STATUS "The opencv libs: ${OpenCV_LIBS}")
