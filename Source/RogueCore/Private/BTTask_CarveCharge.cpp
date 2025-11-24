#include "BTTask_CarveCharge.h"

UBTTask_CarveCharge::UBTTask_CarveCharge() {
    this->ChargeSpeed = 2000.00f;
    this->CarveFrequency = 4.00f;
    this->CarveRadius = 150.00f;
    this->CarveLimit = -1.00f;
    this->MaxTurnAnglePerSeconds = 2.00f;
    this->OvershootDistance = 500.00f;
    this->OvershootCarveLimit = -1.00f;
    this->MinTrackingDistance = 500.00f;
    this->MaxChargeDistance = 5000.00f;
    this->AccelerationTime = 0.50f;
    this->IsCarvingEnabled = true;
}


