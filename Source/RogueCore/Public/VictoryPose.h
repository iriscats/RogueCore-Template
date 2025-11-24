#pragma once
#include "CoreMinimal.h"
#include "Aquisitionable.h"
#include "SavablePrimaryDataAsset.h"
#include "VictoryPose.generated.h"

class AActor;
class UAnimSequence;
class UItemAquisitionBase;
class UObject;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UVictoryPose : public USavablePrimaryDataAsset, public IAquisitionable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UItemAquisitionBase* Aquisition;

    TArray<TSoftObjectPtr<UAnimSequence>> Walks;

    TSoftObjectPtr<UAnimSequence> Pose;

    TSoftClassPtr<AActor> Prop_Actor;

    TSoftObjectPtr<UAnimSequence> Prop_Walk;

    TSoftObjectPtr<UAnimSequence> Prop_Pose;

    TSoftObjectPtr<UAnimSequence> Prop_Idle;

    UVictoryPose();

    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))

    void Unlock(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText Description;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemAquisitionBase* Aquisition;
    TArray<TSoftObjectPtr<UAnimSequence>> Walks;
    TSoftObjectPtr<UAnimSequence> Pose;
    TSoftClassPtr<AActor> Prop_Actor;
    TSoftObjectPtr<UAnimSequence> Prop_Walk;
    TSoftObjectPtr<UAnimSequence> Prop_Pose;
    TSoftObjectPtr<UAnimSequence> Prop_Idle;
    UVictoryPose();
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
    void Unlock(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void ResetUnlock(UObject* WorldContextObject, UPlayerCharacterID* characterID);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool IsUnlockedNotFromStart(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    bool IsUnlocked(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    void Equip(UObject* WorldContextObject, UPlayerCharacterID* characterID) const;
    // Fix for true pure virtual functions not being implemented
};
