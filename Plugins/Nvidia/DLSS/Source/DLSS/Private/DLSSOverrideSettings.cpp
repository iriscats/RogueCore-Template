#include "DLSSOverrideSettings.h"

UDLSSOverrideSettings::UDLSSOverrideSettings() {
    this->bShowDLSSIncompatiblePluginsToolsWarnings = true;
    this->ShowDLSSSDebugOnScreenMessages = EDLSSSettingOverride::UseProjectSettings;
    this->EnableDLSSInEditorViewportsOverride = EDLSSSettingOverride::UseProjectSettings;
    this->EnableDLSSInPlayInEditorViewportsOverride = EDLSSSettingOverride::UseProjectSettings;
}


