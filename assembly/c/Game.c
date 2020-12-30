#include <z2.h>
#include "Models.h"
#include "OverlayMenu.h"

/**
 * Hook function called after preparing display buffers for writing during current frame.
 **/
void Game_AfterPrepareDisplayBuffers(GraphicsContext* gfx) {
    // Check if models objheap should finish advancing.
    Models_AfterPrepareDisplayBuffers(gfx);
}

/**
 * Hook function called after game processes next frame.
 **/
void Game_AfterUpdate(GlobalContext* ctxt) {
    OverlayMenu_Draw(ctxt);
}
