# Pixel Art Application
file(GLOB_RECURSE TEMPLATE_SOURCES "*.cpp" "*.c")
file(GLOB_RECURSE TEMPLATE_HEADERS "*.h")

add_library(PixelArtApp ${TEMPLATE_SOURCES} ${TEMPLATE_HEADERS})

target_include_directories(PixelArtApp PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(PixelArtApp PUBLIC
    MatrixOSInterface
    MatrixOSAPPInterface
)

# Register the application class
RegisterApplicationClass(PixelArt)