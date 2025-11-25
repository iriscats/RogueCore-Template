#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "Engine/NetSerialization.h"
#include "Templates/SubclassOf.h"
#include "WeaponFireComponent.h"
#include "ZiplineLauncherComponent.generated.h"

class AZipLineProjectile;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UZiplineLauncherComponent : public UWeaponFireComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ECollisionChannel>> HitCollisionChannels;
    
 
    float ProjectileLocationOffset;
    TSubclassOf<AZipLineProjectile> ProjectileClass;
    UZiplineLauncherComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Fire(FVector_NetQuantize Origin, FVector_NetQuantize Destination);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit();
};
