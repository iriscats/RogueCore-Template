#include "CrawlerAnimInstance.h"

UCrawlerAnimInstance::UCrawlerAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TotalProgressionTime = 1.00f;
    this->bIsInBallisticMove = false;
    this->BallisticPitch = 0.00f;
    this->ProgressionTime = 0.00f;
    this->AttackMoveBlend = 0.00f;
}


