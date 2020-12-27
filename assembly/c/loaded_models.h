#ifndef LOADED_MODELS_H
#define LOADED_MODELS_H

#include <stdbool.h>
#include "models.h"
#include "z2.h"

bool LoadedModels_AddActorModel(struct model model, void* extra, Actor* actor);
bool LoadedModels_ClearActorModels(void);
bool LoadedModels_GetActorModel(struct model* model, void** extra, Actor* actor);
void LoadedModels_RemoveActorModel(Actor* actor);

#endif // LOADED_MODELS_H
