#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "Skinnable.h"
#include "Magazine.generated.h"

class USkinEffect;
class USoundCue;
UCLASS(Blueprintable)
class AMagazine : public AActor, public ISkinnable {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ImpactGroundSound;
    
    AMagazine(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemSkinned(USkinEffect* Skin);
    UFUNCTION(BlueprintCallable)
    void ActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    // Fix for true pure virtual functions not being implemented
};
