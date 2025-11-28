#pragma once
#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "ItemAggregator.h"
#include "Templates/SubclassOf.h"
#include "ItemPlacerAggregator.generated.h"

class AActor;
class AItem;
class AItemMarker;
class UDialogDataAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UItemPlacerAggregator : public UItemAggregator {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlacementUpdatedDelegate, bool, InPlacementValid, const FTransform&, InPlacement);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMarkerDelegate, AItemMarker*, Marker);
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> IgnoreActors;
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMarkerDelegate OnMarkerSpawned;
    FPlacementUpdatedDelegate OnPlacementChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlacementDistance;
    float MaxOffsetZ;
    float MinOffsetZ;
    float ItemHeight;
    UDialogDataAsset* ShoutOnPlaced;
    TSubclassOf<AItemMarker> MarkerType;
    bool CanOnlyPlaceOnTerrain;
    FGameplayTagQuery ExcludeTags;
    TArray<TSoftClassPtr<AActor>> InvalidAroundActors;
    float InvalidAroundSize;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AItemMarker* PlacementMarker;
    AItem* Item;
    bool bIsPlacementActive;
    bool bIsMarkerHidden;
    bool bIsMarkerValid;
    bool bCanPlaceMarker;
    FTransform LastPlacement;
    bool IsLastTransformValid;
    UItemPlacerAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleValid(bool Valid);
    void TogglePlacement(bool Inactive);
    void ToggleMarkerHidden(bool InHidden);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPlacementEx(FTransform& Placement, bool& OutValidLocation, bool& OutValidMarker) const;
    bool GetPlacement(FTransform& Placement) const;
    void ClearIgnoredActors();
    void AddIgnoredActor(AActor* InActor);
};
