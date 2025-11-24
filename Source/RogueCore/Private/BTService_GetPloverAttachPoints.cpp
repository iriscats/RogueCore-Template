#include "BTService_GetPloverAttachPoints.h"

UBTService_GetPloverAttachPoints::UBTService_GetPloverAttachPoints() {
    this->TargetPoints = NULL;
    this->PositioningMaxRange = 0.00f;
    this->PositioningMinRange = 0.00f;
    this->PositioningMode = EPloverPositioningMode::Above;
}


