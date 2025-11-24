#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "SoftReferenceProvider.h"
#include "PawnAffliction.generated.h"

class UAfflictionEffect;
class UDialogDataAsset;
class UPlayerAfflictionOverlay;
class USoundBase;
class UTexture2D;
UCLASS(Blueprintable)
class UPawnAffliction : public UDataAsset, public ISoftReferenceProvider {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UTexture2D* Icon;

    

    FColor IconColor;

    FColor IconColorBG;

    bool bShowPlayerIcon;

    bool bShowOnEnemyHealthbar;

    UPlayerAfflictionOverlay* AfflictionOverlay;

    TArray<TSoftClassPtr<UAfflictionEffect>> EnemyEffects;

    TArray<TSoftClassPtr<UAfflictionEffect>> PlayerFirstPersonEffects;

    TArray<TSoftClassPtr<UAfflictionEffect>> PlayerThirdPersonEffects;

    UDialogDataAsset* PlayerShoutOnBegin;

    USoundBase* StartSoundForLocalPlayer;

    USoundBase* StopSoundForLocalPlayer;

    UPawnAffliction();

    // Fix for true pure virtual functions not being implemented



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    FColor IconColor;
    FColor IconColorBG;
    bool bShowPlayerIcon;
    bool bShowOnEnemyHealthbar;
    UPlayerAfflictionOverlay* AfflictionOverlay;
    TArray<TSoftClassPtr<UAfflictionEffect>> EnemyEffects;
    TArray<TSoftClassPtr<UAfflictionEffect>> PlayerFirstPersonEffects;
    TArray<TSoftClassPtr<UAfflictionEffect>> PlayerThirdPersonEffects;
    UDialogDataAsset* PlayerShoutOnBegin;
    USoundBase* StartSoundForLocalPlayer;
    USoundBase* StopSoundForLocalPlayer;
    UPawnAffliction();
    // Fix for true pure virtual functions not being implemented
};
