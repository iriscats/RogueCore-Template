#pragma once
#include "CoreMinimal.h"


#include "CarriableItem.h"
#include "ResourcePouch.generated.h"

class AActor;
class UCarriableInstantUsable;
class USoundCue;
UCLASS(Blueprintable)
class AResourcePouch : public ACarriableItem {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCarriableInstantUsable* usable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ImpactGroundSound;
    AResourcePouch(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
