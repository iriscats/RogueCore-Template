#include "JettyBootSettings.h"

UJettyBootSettings::UJettyBootSettings() {
    this->LevelSettings.AddDefaulted(1);
}

FJettyBootSetting UJettyBootSettings::GetLevelSetting(int32 inLevel) const {
    return FJettyBootSetting{};
}


