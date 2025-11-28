#pragma once
#include "CoreMinimal.h"
#include "ProjectileAttackBaseComponent.h"
#include "ProjectileAttackComponent.generated.h"

class UAnimMontage;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileAttackComponent : public UProjectileAttackBaseComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ManualyComplete;
    
    UProjectileAttackComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void AddAttackMontage(UAnimMontage* attackMontage);
};
