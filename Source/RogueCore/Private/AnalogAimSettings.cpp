#include "AnalogAimSettings.h"

FAnalogAimSettings::FAnalogAimSettings() {
    this->AimRate = FVector2D(0.0f, 0.0f);
    this->SensitivityCurve = NULL;
    this->LookAtStickyness = 0.00f;
    this->StickynessRecoverySpeed = 0.00f;
    this->StickynessMaxSensitivity = 0.00f;
    this->ThirdPersonLookRate = FVector2D(0.0f, 0.0f);
}

