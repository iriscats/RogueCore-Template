#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "FacilityShieldGenerator.generated.h"

UCLASS(Blueprintable, NoExport)
class AFacilityShieldGenerator : public AActor, public IGameplayTagAssetInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    AFacilityShieldGenerator(const FObjectInitializer& ObjectInitializer);
    // IGameplayTagAssetInterface interface
    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    FGameplayTagContainer BP_GetOwnedGameplayTags() const override PURE_VIRTUAL(BP_GetOwnedGameplayTags, return FGameplayTagContainer{};);
};
