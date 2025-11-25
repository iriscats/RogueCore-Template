#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoDrivenWeapon.h"
#include "ZipLineItem.generated.h"

class UDialogDataAsset;
UCLASS(Abstract, Blueprintable, NoExport)
class AZipLineItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    float MinDistance;
    float MinAngle;
    float MaxAngle;
    FGameplayTagQuery ExcludeSurfaceTags;
    AZipLineItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanFireWeapon(FText& FailMsg, UDialogDataAsset*& FailShout);
};
