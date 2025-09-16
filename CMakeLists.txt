# Template Application
file(GLOB_RECURSE TEMPLATE_SOURCES "*.cpp" "*.c")
file(GLOB_RECURSE TEMPLATE_HEADERS "*.h")

add_library(TemplateApp ${TEMPLATE_SOURCES} ${TEMPLATE_HEADERS})

target_include_directories(TemplateApp PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(TemplateApp PUBLIC
    MatrixOSInterface
    MatrixOSAPPInterface
)

# Register the application class
RegisterApplicationClass(Template)