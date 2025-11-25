#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GameplayTagContainer.h"
#include "AnimatedItem.h"
#include "ELaserPointerMarkerType.h"
#include "LaserPointerData.h"
#include "MarkerPlacedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "LaserPointerItem.generated.h"

class AActor;
class ALaserPointerMarker;
class ALaserPointerWaypoint;
class UDialogDataAsset;
class UObject;
class UObjectInfoComponent;
class UPrimitiveComponent;
class USceneComponent;
class UTerrainMaterial;
class UTexture2D;
UCLASS(Abstract, Blueprintable)
class ALaserPointerItem : public AAnimatedItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMarkerPlacedDelegate OnMarkerPlaced;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ALaserPointerMarker> MarkerType;
    TSubclassOf<ALaserPointerMarker> SecondaryMarkerType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALaserPointerMarker> ActiveMarker;
    FGameplayTagContainer enemyTags;
    TSubclassOf<ALaserPointerWaypoint> WaypointType;
    int32 MaxWaypoints;
    TArray<ALaserPointerWaypoint*> Waypoints;
    int32 NextWaypointIndex;
    float MarkerLifeTime;
    UDialogDataAsset* DefaultLookAtShout;
    UDialogDataAsset* DefaultEnemyShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PointerComponent;
    FHitResult LookAtHit;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObjectInfoComponent> LookAtInfo;
    TWeakObjectPtr<UTerrainMaterial> LookAtTerrainMaterial;
    FLaserPointerData LookAtData;
    float LookAtDistance;
    UDialogDataAsset* LookAtShout;
    UDialogDataAsset* MissionControlLookAtShout;
    ALaserPointerItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void UnlockToMinersManual(UObject* WorldContextObject, FGuid ObjectId);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ToggleLaserVisible(bool aVisible);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlaceMarker(FVector Location, AActor* Actor, UPrimitiveComponent* Cmponent, UTerrainMaterial* TerrainMaterial, ELaserPointerMarkerType eMarkerType);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SecondaryUse();
 
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void RevealTerrainScannerMeshesForMarkedActorInternal(AActor* InActor);
 
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RevealTerrainScannerMeshesForMarkedActor(AActor* InActor);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPointOfInterest(AActor* targetActor, FVector TargetLocation, UTexture2D* TargetIcon);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    void GetPointTransform(FTransform& PointTransform);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetActiveMarkerLocation() const;
};
