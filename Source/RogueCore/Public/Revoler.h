#pragma once
#include "CoreMinimal.h"
#include "EUpdateDamageNumberColor.h"
#include "HitscanWeapon.h"
#include "StackingDamageNumberSource.h"
#include "Revoler.generated.h"

class AActor;
class UDamageComponent;
class UFSDPhysicalMaterial;
UCLASS(Blueprintable, NoExport)
class ARevoler : public AHitscanWeapon, public IStackingDamageNumberSource {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnKillFearFactor;
    float OnKillFearRange;
    ARevoler(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    // Fix for true pure virtual functions not being implemented
    float GetStackingTimeLimit() const override PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    int32 GetMaxCombinationsPerentry() const override PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    EUpdateDamageNumberColor GetColorBehaviour() const override PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
