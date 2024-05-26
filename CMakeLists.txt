cmake_minimum_required(VERSION 3.27)
project(chk_lib_launcher C)

add_subdirectory("external")

set(src "launcher.c" "main.c")
set(hdr "launcher.h")

list(TRANSFORM src PREPEND "src/")
list(TRANSFORM hdr PREPEND "include/chk/launcher/")

add_executable(chk_launcher ${src} ${hdr})
# add_library(chk::launcher ALIAS chk_launcher)

target_compile_features(chk_launcher PUBLIC c_std_11)
target_include_directories(chk_launcher PUBLIC "include")

target_link_libraries(chk_launcher PUBLIC chk::core chk::win chk::renderer)
# target_link_libraries(chk_launcher PRIVATE )
