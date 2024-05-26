#pragma once

#include <chk/core/types.h>
#include <chk/renderer/renderer.h>
#include <chk/win/win.h>

typedef struct LauncherConfig {
    WinConfig      win;
    RendererConfig renderer;
} LauncherConfig;

bool chk_launcher_config_get_default(LauncherConfig* c);

typedef struct Launcher {
    Win      win;
    Renderer renderer;
} Launcher;

bool chk_launcher_create(Launcher* l, LauncherConfig* c);
bool chk_launcher_destroy(Launcher* l);

bool chk_launcher_run(Launcher* l);
