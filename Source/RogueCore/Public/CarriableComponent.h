#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CarriableEventDelegate.h"
#include "Throwable.h"
#include "CarriableComponent.generated.h"

class APlayerCharacter;
class UDialogDataAsset;
class UItemCharacterAnimationSet;
class UUseAnimationSetting;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCarriableComponent : public UActorComponent, public IThrowable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCarriableEvent OnPickedUp;
    
    FCarriableEvent OnDropped;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDialogDataAsset> ShoutWhileCarrying;
    UItemCharacterAnimationSet* OverrideCarryAnimationSet;
    UUseAnimationSetting* OverrideThrowAnimationSet;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* CarriedBy;
    FVector Offset;
    UCarriableComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool PickupItem(APlayerCharacter* byCharacter);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DropItem();
    void AttachChanged(bool Attached, const FVector PrevScale);
    // Fix for true pure virtual functions not being implemented
};
