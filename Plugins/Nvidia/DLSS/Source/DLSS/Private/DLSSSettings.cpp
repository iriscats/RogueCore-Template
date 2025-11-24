#include "DLSSSettings.h"

UDLSSSettings::UDLSSSettings() {
    this->bAllowOTAUpdate = true;
    this->NVIDIANGXApplicationId = 0;
    this->BiasCurrentColorStencilValue = 8;
    this->bEnableDLSSD3D12 = true;
    this->bEnableDLSSD3D11 = true;
    this->bEnableDLSSVulkan = true;
    this->bShowDLSSIncompatiblePluginsToolsWarnings = true;
    this->bEnableDLSSInEditorViewports = false;
    this->bEnableDLSSInPlayInEditorViewports = true;
    this->bShowDLSSSDebugOnScreenMessages = true;
    this->bGenericDLSSSRBinaryExists = false;
    this->bCustomDLSSSRBinaryExists = false;
    this->DLAAPreset = EDLSSPreset::Default;
    this->DLSSQualityPreset = EDLSSPreset::Default;
    this->DLSSBalancedPreset = EDLSSPreset::Default;
    this->DLSSPerformancePreset = EDLSSPreset::Default;
    this->DLSSUltraPerformancePreset = EDLSSPreset::Default;
    this->bGenericDLSSRRBinaryExists = false;
    this->bCustomDLSSRRBinaryExists = false;
    this->DLAARRPreset = EDLSSRRPreset::Default;
    this->DLSSRRQualityPreset = EDLSSRRPreset::Default;
    this->DLSSRRBalancedPreset = EDLSSRRPreset::Default;
    this->DLSSRRPerformancePreset = EDLSSRRPreset::Default;
    this->DLSSRRUltraPerformancePreset = EDLSSRRPreset::Default;
}


