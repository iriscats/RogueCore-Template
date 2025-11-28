#pragma once
#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeepPathFinderSize.h"
#include "DeepPathFinderType.h"
#include "ESpecialDebrisType.h"
#include "TerrainFunctionLibrary.generated.h"

class UObject;
class UTerrainMaterial;
UCLASS(Blueprintable)
class UTerrainFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTerrainFunctionLibrary();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetDebrisTransformsInSphere(UObject* WorldContextObject, TArray<FMatrix>& outPositions, const FVector& Location, const float& Radius, const ESpecialDebrisType& debrisType, float minDistToOther, bool calcPriority);
    
    static TArray<FVector> GetAllNavPointsInSphere(UObject* WorldContextObject, FVector Origin, float Radius, DeepPathFinderSize pfSize, const FVector searchNormal, float maxDegreesToSearchNormal);
    static TArray<FVector> FindPath(UObject* WorldContextObject, FVector Origin, FVector Destination, DeepPathFinderSize pfSize, DeepPathFinderType pfType);
    static void FindNearestSurfacePoint(UObject* WorldContextObject, FVector InPoint, FVector& outPoint, FVector& Normal, bool& IsBlocked);
    static void FindNearestSurfaceNormal(UObject* WorldContextObject, FVector InPoint, FVector& Normal);
    static bool DoesPathExist(UObject* WorldContextObject, FVector Origin, FVector Destination, DeepPathFinderSize pfSize, DeepPathFinderType pfType);
    static void CreateExplosionCrater2(UObject* WorldContextObject, FVector Location, float CarveDiameter, float carveNoiseSize, float carveBurnThickness, FVector Normal, float NormalOffset, float NormalSqueeze, bool allowCustomBurntMaterial, bool DissolvePlatforms, UTerrainMaterial* overrideBurnedMaterial);
    static void CreateExplosionCrater(UObject* WorldContextObject, FVector Location, float CarveDiameter, float carveNoiseSize, float carveBurnThickness, bool allowCustomBurntMaterial, UTerrainMaterial* overrideBurnedMaterial);
    static int32 CountDebrisOfType(UObject* WorldContextObject, ESpecialDebrisType debrisType);
    static int32 CountDebrisInSphere(UObject* WorldContextObject, FVector Location, float Radius, ESpecialDebrisType debrisType);
};
