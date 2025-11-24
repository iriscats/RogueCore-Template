#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "EOutline.h"
#include "OutlineComponent.generated.h"

class AActor;
class AItem;
class APlayerCharacter;
class UHealthComponentBase;
class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOutlineComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOutlineChanged, EOutline, InOutline);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOutlineChanged OnOutlineChanged;
    FDelegate OnPingedByLaserPointer;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOutline DefaultOutline;
    bool ActiveOnHoldTAB;
    bool DoesTrackWithOutlineType;
    float CustomLaserPointDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LockCounter;
    EOutline CurrentOutline;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> OutlinedComponents;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> ExcludedComponents;
    TArray<UPrimitiveComponent*> IncludedComponents;
    TWeakObjectPtr<APlayerCharacter> Character;
    UOutlineComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnlockOutline();
    void ToggleDefaultOutline(bool visible);
    void SetOutline(EOutline Outline);
    void RemoveFromOutline(UPrimitiveComponent* Component);
    void OnToggleOutlineType(EOutline Outline, bool visible, bool checkIfOwnerIsAlive);
    void OnToggleOutline(bool visible);
    void OnOwnerDeath(UHealthComponentBase* HealthComponent);
    void OnItemUnequipped(AItem* Item);
    void OnItemEquipped(AItem* Item);
    void LockOutline();
    void EnableActivateOnHoldTab();
    void DisableActiveOnHoldTab();
    void AddToOutline(UPrimitiveComponent* Component);
    void AddActorToOutline(AActor* Actor);
};
