if (NOT TARGET chk_core)
    add_subdirectory("chk_core")
endif()

if (NOT TARGET chk_win)
    add_subdirectory("chk_win")
endif()

if (NOT TARGET chk_renderer)
    add_subdirectory("chk_renderer")
endif()
