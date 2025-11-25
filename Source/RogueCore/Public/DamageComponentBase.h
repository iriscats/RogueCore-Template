#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "EDamageComponentType.h"
#include "EOverrideCrit.h"
#include "OnEnemyDamagedDelegateDelegate.h"
#include "OnEnemyKilledDelegateDelegate.h"
#include "DamageComponentBase.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UPrimitiveComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDamageComponentBase : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnHitDeadTarget;
    
    FOnEnemyDamagedDelegate OnTargetDamagedEvent;
    FOnEnemyKilledDelegate OnTargetKilledEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageComponentType DamageComponentType;
    UDamageComponentBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false)
    void DamageTarget(AActor* Target, const FVector& Location, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* Material, int32 BoneIndex, EOverrideCrit overrideCrit, int32 overrideCritLevel) const;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DamageArmor_Server(AActor* Target, UPrimitiveComponent* collider, int32 BoneIndex, const FVector& impactLocation) const;
    void DamageArmor_All(AActor* Target, UPrimitiveComponent* collider, int32 BoneIndex) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ArmorSupportsLocalOnlyCall(AActor* Target) const;
};
