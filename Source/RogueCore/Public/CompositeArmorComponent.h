#pragma once
#include "CoreMinimal.h"
#include "ArmorDamageInfo.h"
#include "ArmorPrimitiveDamagedDelegateDelegate.h"
#include "ArmorPrimitiveDestroyedDelegate.h"
#include "BaseArmorDamageComponent.h"
#include "CompositeArmorItem.h"
#include "CompositeArmorComponent.generated.h"

class UFXSystemAsset;
class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCompositeArmorComponent : public UBaseArmorDamageComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorPrimitiveDestroyed OnArmorPartDestroyedEvent;
    
    FArmorPrimitiveDamagedDelegate OnArmorPartDamagedEvent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* BreakParticle;
    bool AffectedByAmorBreak;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCompositeArmorItem> ArmorItems;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ArmorDamageInfo, meta=(AllowPrivateAccess=true))
    FArmorDamageInfo ArmorDamageInfo;
    UCompositeArmorComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_ArmorDamageInfo(FArmorDamageInfo OldValue);
    void AddArmorPart(UPrimitiveComponent* Primitive, float Health, bool overrideAffectedByArmomrBreak, bool NewAffectedByArmorBreak);
};
