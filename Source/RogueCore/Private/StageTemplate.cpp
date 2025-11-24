#include "StageTemplate.h"

UStageTemplate::UStageTemplate() {
    this->StageIcon = NULL;
    this->StageIconSmall = NULL;
    this->StageTypeIndex = 0;
}

bool UStageTemplate::IsLocked(UFSDSaveGame* SaveGame) const {
    return false;
}

int32 UStageTemplate::GetStageTypeIndex() const {
    return 0;
}

UTexture2D* UStageTemplate::GetStageImageLarge() const {
    return NULL;
}

UTexture2D* UStageTemplate::GetStageButtonImage() const {
    return NULL;
}

FObjectiveMissionIcon UStageTemplate::GetPrimaryObjectiveIconFromAsset(UStageTemplate* Mission, bool getSmallVersion) {
    return FObjectiveMissionIcon{};
}

FObjectiveMissionIcon UStageTemplate::GetPrimaryObjectiveIcon(bool getSmallVersion) const {
    return FObjectiveMissionIcon{};
}


