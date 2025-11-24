#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageRelevant.h"
#include "EDamageListenerQualities.h"
#include "ListenerEntry.h"
#include "DamageListenerCollection.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UDamageListenerCollection : public UActorComponent, public IDamageRelevant {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FListenerEntry> Listeners;
    
    UDamageListenerCollection(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasDamageBit(int32 BitMask, EDamageListenerQualities bit);
    // Fix for true pure virtual functions not being implemented
};
