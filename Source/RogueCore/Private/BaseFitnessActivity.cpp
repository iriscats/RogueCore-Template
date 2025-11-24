#include "BaseFitnessActivity.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"

ABaseFitnessActivity::ABaseFitnessActivity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->ActorPlacement = CreateDefaultSubobject<UArrowComponent>(TEXT("ActorPlacement"));
    this->OwnerGym = NULL;
    this->CurrentUser = NULL;
    this->CameraHorizontalLimits = 35.00f;
    this->CameraVerticalLimits = 15.00f;
    this->CameraSpringArms.AddDefaulted(3);
    this->CurrentBestScore = -1;
    this->GymID = -1;
    this->ActorPlacement->SetupAttachment(RootComponent);
}

void ABaseFitnessActivity::StartActivity(APlayerCharacter* Player) {
}

void ABaseFitnessActivity::SetPersonalBest(int32 Best) {
}

void ABaseFitnessActivity::SetOwningGym(AFitnessGym* gym) {
}

void ABaseFitnessActivity::OnRep_CurrentBestScoreName() const {
}

void ABaseFitnessActivity::OnRep_CurrentBestScore() const {
}

APlayerCharacter* ABaseFitnessActivity::GetUserCharacter() {
    return NULL;
}

AFitnessGym* ABaseFitnessActivity::GetOwnerGym() const {
    return NULL;
}


void ABaseFitnessActivity::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABaseFitnessActivity, CurrentUser);
    DOREPLIFETIME(ABaseFitnessActivity, CurrentBestScore);
    DOREPLIFETIME(ABaseFitnessActivity, CurrentBestScoreName);
}


