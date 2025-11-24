#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageData.h"
#include "EElementSourceIntensity.h"
#include "ElementChangeArgs.h"
#include "ElementEventDelegateDelegate.h"
#include "ElementEventState.h"
#include "ElementEventStateLocal.h"
#include "ElementStateArray.h"
#include "ElementComponent.generated.h"

class AActor;
class UDamageTag;
class UElementEventComponent;
class UElementEventType;
class UElementStateDelegates;
class UElementType;
class UHealthComponent;
class UPawnStatsComponent;
class UStatusEffectsComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UElementComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    TMap<UElementEventType*, UElementEventComponent*> EventComponents;

    UPawnStatsComponent* CachedPawnStatComponent;

    UStatusEffectsComponent* CachedStatusEffectsComponent;

    UElementComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElementEventDelegate OnElementEventAdded;
    
    FElementEventDelegate OnElementEventRemoved;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UElementType*> SupportedElements;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UElementType*> BlacklistedElements;
    TMap<UElementEventType*, float> EventDamageBonus;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FElementStateArray ElementStates;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Events, meta=(AllowPrivateAccess=true))
    TArray<FElementEventState> Events;
    TMap<UElementEventType*, FElementEventStateLocal> LocalEventState;
    TMap<UElementType*, UElementStateDelegates*> ElementDelegates;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<UElementEventType*, UElementEventComponent*> EventComponents;
    UPawnStatsComponent* CachedPawnStatComponent;
    UStatusEffectsComponent* CachedStatusEffectsComponent;
    UElementComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool TryPushElementSource(UElementType* ElementType, AActor* Target, float Value, EElementSourceIntensity Intensity);
    static bool TryPopElementSource(UElementType* ElementType, AActor* Target, float Value, EElementSourceIntensity Intensity);
    UFUNCTION(BlueprintCallable)
    void SetServerUserDataBool(UElementType* InElement, const bool InBool);
    void ResetElementValue(UElementType* ElementType);
    void RemoveElementEventIfActive(UElementEventType* InEventType);
    void PushElementEvent(UElementEventType* InEventType, UElementType* InTriggerByElement, AActor* InSource);
    UFUNCTION()
    void OnRep_Events(TArray<FElementEventState> PrevEvents);
    void OnOwnerDeath(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& Tags);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventActive(UElementEventType* ElementEventType) const;
    bool IsElementSupported(UElementType* InElement) const;
    static void IsElementActiveOnTarget(AActor* Target, UElementEventType* EventType, bool& OutResult);
    TArray<UElementType*> GetSupportedElements() const;
    bool GetServerUserDataBool(UElementType* InElement) const;
    TArray<UElementType*> GetRelatedElementTypes(const FElementEventState& InEventState) const;
    float GetElementValueEffect(UElementType* ElementType) const;
    UElementStateDelegates* GetElementStateDelegates(UElementType* ElementType);
    float GetElementLocalChangeDelta(UElementType* ElementType) const;
    void GetElementEventStatesForType(UElementType* ElementType, TArray<FElementEventState>& OutStates) const;
    UElementEventComponent* GetElementEventComponent(UElementEventType* InElementType) const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    float GetCurrentElementValue(UElementType* ElementType) const;
    float ChangeElementValue(UElementType* ElementType, float ChangeValue, const FElementChangeArgs& InArgs, bool MarkReplicateDirty);
    bool AreAnyEventsActiveForElement(UElementType* ElementType) const;
};
