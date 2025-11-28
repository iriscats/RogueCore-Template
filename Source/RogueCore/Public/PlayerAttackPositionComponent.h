#pragma once
#include "CoreMinimal.h"
#include "AttackerPositioningComponent.h"
#include "PlayerAttackPositionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerAttackPositionComponent : public UAttackerPositioningComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnZiplineFlyingModifier;
    
    float OnZiplineWalkingModifier;
    UPlayerAttackPositionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetGameplayModifier(float Modifier);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGameplayModifier() const;
};
