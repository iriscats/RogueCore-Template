#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpecialAttackComponent.h"
#include "AttachAttack.generated.h"

class UPloverTargetSockets;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAttachAttack : public USpecialAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdjustedOffset;
    
    float LerpTime;
    UPloverTargetSockets* TargetSettings;
    UAttachAttack(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StartLerp(FVector From, FVector To);
};
