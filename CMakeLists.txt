file(GLOB_RECURSE TEMPLATE_SOURCES "*.cpp" "*.c")
file(GLOB_RECURSE TEMPLATE_HEADERS "*.h")

add_library(PixelArt ${TEMPLATE_SOURCES} ${TEMPLATE_HEADERS})

target_include_directories(PixelArt PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(PixelArt PUBLIC
	MatrixOSInterface
	MatrixOSAPPInterface
)

# Register the application class
RegisterApplicationClass(PixelArt)
