#pragma once
#include "CoreMinimal.h"

#include "Subsystems/WorldSubsystem.h"
#include "FlareMeta.h"
#include "ShadowQualityChangedDelegate.h"
#include "FlareController.generated.h"

class AActor;
class AFlare;
class AFlareGunProjectile;
class UObject;
UCLASS(Blueprintable)
class UFlareController : public UWorldSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShadowQualityChanged OnShadowQualityChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FFlareMeta> FlaresMeta;
    UFlareController();
    UFUNCTION(BlueprintCallable)
    static void UnregisterFlareGunProjectile(AFlareGunProjectile* flareprj);
    static void UnregisterFlare(AFlare* Flare);
    static void RegisterFlareGunProjectile(AFlareGunProjectile* flareprj);
    static void RegisterFlare(AFlare* Flare);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* FindFlareNear(UObject* WorldContextObject, FVector Pos, bool allowMoving, float maxLightRadiusFraction);
};
