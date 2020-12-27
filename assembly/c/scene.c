#include "actor_ext.h"
#include "loaded_models.h"
#include "models.h"
#include "z2.h"

/**
 * Hook function used after the scene initialize function has been called.
 **/
void scene_after_init(GlobalContext *game) {
    // Set all actor ext heap entries to clear
    ActorExt_Clear();
    // Clear the models object heap
    models_clear_object_heap();
    // Clear loaded actor model info
    LoadedModels_ClearActorModels();
}
