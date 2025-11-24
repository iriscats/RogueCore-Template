#include "StreamlineOverrideSettings.h"

UStreamlineOverrideSettings::UStreamlineOverrideSettings() {
    this->LoadDebugOverlayOverride = EStreamlineSettingOverride::UseProjectSettings;
    this->AllowOTAUpdateOverride = EStreamlineSettingOverride::UseProjectSettings;
    this->EnableDLSSFGInPlayInEditorViewportsOverride = EStreamlineSettingOverride::UseProjectSettings;
    this->UseSlSetTagOverride = EStreamlineSettingOverride::UseProjectSettings;
}


