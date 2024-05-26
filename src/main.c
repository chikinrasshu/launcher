#include <chk/core/log.h>
#include <chk/core/print.h>
#include <chk/launcher/launcher.h>

CHK_WIN_ON_UPDATE(on_update) {
    (void)dt;

    Launcher* l = user_ptr;
    if (!l) {
        chk_warn("Launcher", "l was NULL");
        return;
    }

    if (l->win.changed.dark) {
        chk_info_f("Launcher", "Dark mode changed to %s",
                   l->win.state.dark ? "YES" : "NO");
    }
}

CHK_WIN_ON_RENDER(on_render) {
    Launcher* l = user_ptr;
    if (!l) {
        chk_warn("Launcher", "l was NULL");
        return;
    }

    chk_renderer_begin(&l->renderer);

    // Do some rendering...
    chk_renderer_clear(&l->renderer, (RGBA){0.1f, 0.2f, 0.3f, 1.0f});

    chk_renderer_line(&l->renderer, (V2){32.0f, 24.0f}, (V2){64.0f, 96.0f},
                      (RGBA){0.6f, 0.5f, 0.4f, 1.0f});

    chk_renderer_end(&l->renderer);
}

CHK_WIN_ON_DBG_UI(on_dbg_ui) {
    Launcher* l = user_ptr;
    if (!l) {
        chk_warn("Launcher", "l was NULL");
        return;
    }
}

S32 main(S32 argc, char** argv) {
    LauncherConfig c = {};
    if (!chk_launcher_config_get_default(&c)) { return 1; }

    Launcher l = {};
    if (!chk_launcher_create(&l, &c)) { return 1; }

    l.win.fn.user_ptr  = &l;
    l.win.fn.on_update = on_update;
    l.win.fn.on_render = on_render;
    l.win.fn.on_dbg_ui = on_dbg_ui;

    if (!chk_launcher_run(&l)) { return 1; }
    if (!chk_launcher_destroy(&l)) { return 1; }

    return 0;
}
