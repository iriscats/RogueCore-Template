#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CraftingCost.h"
#include "Templates/SubclassOf.h"
#include "ItemData.generated.h"

class AActor;
class UItemID;
class UObject;
class UResourceData;
class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UItemData : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* ItemID;
    
    UTexture2D* IconLine;
    UTexture2D* IconBG;
    UTexture2D* IconDetailed;
    TSoftObjectPtr<UTexture2D> PreviewImage;
    TSoftClassPtr<AActor> PreviewActor;
    FText Name;
    FText Category;
    FText Description;
    int32 CreditCost;
    TMap<UResourceData*, float> ResourceCost;
    int32 RequiredCharacterLevel;
    UItemData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetPreviewImageSoft() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    UTexture2D* GetPreviewImage(UObject* WorldContext) const;
    TSubclassOf<AActor> GetPreviewActorClass() const;
    TArray<FCraftingCost> GetCraftingCost() const;
};
