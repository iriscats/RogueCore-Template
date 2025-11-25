#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActiveMusicItem.h"
#include "MusicReplicator.generated.h"

UCLASS(Blueprintable)
class AMusicReplicator : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActiveMusic, meta=(AllowPrivateAccess=true))
    TArray<FActiveMusicItem> ActiveMusic;
    
    AMusicReplicator(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_ActiveMusic();
};
