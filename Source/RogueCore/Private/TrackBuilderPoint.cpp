#include "TrackBuilderPoint.h"

FTrackBuilderPoint::FTrackBuilderPoint() {
    this->IsInitialized = false;
    this->PlacementState = ETrackBuildPlacementState::NotBeingPlaced;
    this->bPointValid = false;
}

