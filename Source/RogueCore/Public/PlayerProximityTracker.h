#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "PlayerProximityDelegateDelegate.h"
#include "PlayerSphere.h"
#include "ProximityTriggerItem.h"
#include "PlayerProximityTracker.generated.h"

class UObject;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerProximityTracker : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistanceBetweenPlayers;
    
    float PlayerSpheresUpdateRatePerSecond;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayerSphere> PlayerSpheres;
    TArray<FProximityTriggerItem> LocalPlayerProximityTriggers;
    TArray<FProximityTriggerItem> AnyPlayerProximityTriggers;
    UPlayerProximityTracker(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void Receive_RegisterForLocalPlayerProximity(UObject* WorldContextObject, const FVector& Location, float Distance, const FPlayerProximityDelegate& proximityCallback, bool triggerOnlyOnce);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void Receive_RegisterForAnyPlayerProximity(UObject* WorldContextObject, const FVector& Location, float Distance, const FPlayerProximityDelegate& proximityCallback, bool triggerOnlyOnce);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPlayerSphere GetPrimarySphere() const;
    TArray<FPlayerSphere> GetPlayerSpheres() const;
};
