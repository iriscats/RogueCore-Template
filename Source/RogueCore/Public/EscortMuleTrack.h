#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "EscortMuleTrack.generated.h"

UCLASS(Abstract, Blueprintable, NoExport)
class AEscortMuleTrack : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FGameplayTagContainer GameplayTags;



    AEscortMuleTrack(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;

    AEscortMuleTrack(const FObjectInitializer& ObjectInitializer);
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const;
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;
    FGameplayTagContainer BP_GetOwnedGameplayTags() const;
};
