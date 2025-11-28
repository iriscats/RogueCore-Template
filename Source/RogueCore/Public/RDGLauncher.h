#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "RDGLauncher.generated.h"

class URDGComponent;
UCLASS(Abstract, Blueprintable)
class ARDGLauncher : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<URDGComponent*> ActiveGrenades;
    
    ARDGLauncher(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_DetonateAll();
    UFUNCTION(BlueprintCallable)
    void RegisterGrenade(URDGComponent* Grenade);
};
