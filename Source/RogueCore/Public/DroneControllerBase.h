#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "LaserPointerTarget.h"
#include "DroneControllerBase.generated.h"

class AFSDPlayerState;
class APlayerCharacter;
UCLASS(Blueprintable, NoExport)
class ADroneControllerBase : public AAIController {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<APlayerCharacter>> ControllingPlayers;

private:
    friend struct Z_Construct_UClass_ADroneControllerBase_Statics;
    
    ADroneControllerBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnShout(APlayerCharacter* Player);
    void OnSecondaryLaserPointer(const FLaserPointerTarget& HitInfo);
    void OnSalute(APlayerCharacter* Player);
    void OnPrimaryLaserpointer(const FLaserPointerTarget& HitInfo);
    void OnPlayerLeave(AFSDPlayerState* State);
    void OnPlayerJoin(APlayerCharacter* Player);
};
