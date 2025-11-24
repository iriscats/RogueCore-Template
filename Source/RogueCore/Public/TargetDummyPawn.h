#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Targetable.h"
#include "TargetDummyPawn.generated.h"

UCLASS(Abstract, Blueprintable, NoExport)
class ATargetDummyPawn : public AActor, public IGameplayTagAssetInterface, public ITargetable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    ATargetDummyPawn(const FObjectInitializer& ObjectInitializer);

    // IGameplayTagAssetInterface interface
    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

    // ITargetable interface - implemented using GameplayTags
    UFUNCTION(BlueprintCallable)
    virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const;
    virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;
    virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;
};
