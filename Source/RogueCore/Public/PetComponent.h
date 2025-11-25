#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PetComponent.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPetComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=ReceiveOwningPlayerChanged, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> OwningPlayer;
    
    UPetComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOwningPlayerChanged();
};
