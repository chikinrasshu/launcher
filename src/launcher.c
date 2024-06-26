#include <chk/launcher/launcher.h>

/******************************************************************************/
/* LauncherConfig impl                                                        */
/******************************************************************************/

bool chk_launcher_config_get_default(LauncherConfig* c) {
    if (!c) { return false; }

    if (!chk_win_config_get_default(&c->win)) { return false; }
    if (!chk_renderer_config_get_default(&c->renderer)) { return false; }

    if (c->renderer.kind == RendererKind_OpenGL) { c->win.uses_opengl = true; }

    return true;
}

/******************************************************************************/
/* Launcher impl                                                              */
/******************************************************************************/

bool chk_launcher_create(Launcher* l, LauncherConfig* c) {
    if (!l) { return false; }

    if (!chk_win_create(&l->win, &c->win)) { return false; }
    c->renderer.win_impl = l->win.impl;

    if (!chk_renderer_create(&l->renderer, &c->renderer)) { return false; }

    return true;
}

bool chk_launcher_destroy(Launcher* l) {
    if (!l) { return false; }

    if (!chk_renderer_destroy(&l->renderer)) { return false; }
    if (!chk_win_destroy(&l->win)) { return false; }

    return true;
}

bool chk_launcher_run(Launcher* l) {
    if (!l) { return false; }

    return chk_win_run(&l->win);
}
