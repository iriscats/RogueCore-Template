#pragma once
#include "CoreMinimal.h"
#include "ResourceData.h"
#include "Templates/SubclassOf.h"
#include "CollectableResourceData.generated.h"

class AActor;
class AProceduralSetup;
class UCollectableResourceCreator;
class UDebrisBase;
class UDebrisPositioning;
UCLASS(Blueprintable)
class UCollectableResourceData : public UResourceData {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ScaleToRoomResourceMultiplier;

    UCollectableResourceData();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDesiredAmount(AProceduralSetup* pls) const;

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCollectableResourceCreator* ResourceCreator;

    UDebrisPositioning* Positioning;
    float Rarity;
    float InfluenceRadius;
    TArray<TSoftObjectPtr<UDebrisBase>> Debris;
    bool UseTerrainPlacement;
    TArray<TSoftClassPtr<AActor>> CollectableClasses;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> CollectableClassesLoaded;
};
