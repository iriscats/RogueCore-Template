#include "UsableComponentBase.h"

UUsableComponentBase::UUsableComponentBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CallbackKeys = 1;
    this->UseCooldown = 0.00f;
    this->AnimationSettings = NULL;
    this->Priority = 0;
    this->RestrictToCollider = NULL;
    this->UsableHidesPlaceables = true;
    this->IsRayTraceTriggered = true;
    this->ResetUsingOnCompletion = true;
    this->AccessCondition = NULL;
    this->IsClientPredictive = false;
    this->ThirdPersonWhileUsing = false;
    this->CapitalUseText = true;
}

void UUsableComponentBase::SetUseRestrictions(UUseConditionSet* Set) {
}

void UUsableComponentBase::SetRayTraceTriggered(bool rayTraceTriggered) {
}

void UUsableComponentBase::SetAnimationSettings(UUseAnimationSetting* Settings) {
}

FText UUsableComponentBase::GetUseText_Implementation(APlayerCharacter* User) {
    return FText::GetEmpty();
}

float UUsableComponentBase::GetUseProgressInPercent(APlayerCharacter* User) const {
    return 0.0f;
}

UTexture2D* UUsableComponentBase::GetUsableIcon() const {
    return NULL;
}

bool UUsableComponentBase::GetShowUsingUI() const {
    return false;
}

bool UUsableComponentBase::GetIsRayTraceTriggerd() const {
    return false;
}

bool UUsableComponentBase::GetIsHovered() const {
    return false;
}

APlayerCharacter* UUsableComponentBase::GetHoveredBy() const {
    return NULL;
}

bool UUsableComponentBase::GetHideProgressBar(APlayerCharacter* User) const {
    return false;
}

bool UUsableComponentBase::GetHideActionText(APlayerCharacter* User) const {
    return false;
}

bool UUsableComponentBase::GetCapitalUseText() const {
    return false;
}

UAccessCondition* UUsableComponentBase::GetAccessCondition() const {
    return NULL;
}

void UUsableComponentBase::EndUse(APlayerCharacter* User) {
}

void UUsableComponentBase::BeginUse(APlayerCharacter* User, EInputKeys Key) {
}


