project(Lib C CXX)
set(PROJECT_NAME Lib)
enable_language(C CXX)
get_property(languages GLOBAL PROPERTY ENABLED_LANGUAGES)
set(Lib_DESCRIPTION "Lib para projeto de comunicacao UDP")
set(HEADER_FILES ${PROJECT_SOURCE_DIR}/Include/Lib.h)
project(Lib LANGUAGES C CXX VERSION 0.0.1)

include_directories(${PROJECT_SOURCE_DIR}/Include)

add_library(Lib STATIC
   Comunicacao.c
   Manipulacao_de_Arquivos.c
   )

install(TARGETS Lib DESTINATION Lib)
install(FILES ${HEADER_FILES} DESTINATION Include)
