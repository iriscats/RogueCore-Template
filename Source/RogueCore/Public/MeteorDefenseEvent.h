#pragma once
#include "CoreMinimal.h"
#include "GameEvent.h"
#include "ProgressShout.h"
#include "MeteorDefenseEvent.generated.h"

class APlagueMeteor;
UCLASS(Blueprintable, NoExport)
class AMeteorDefenseEvent : public AGameEvent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProgressShout> ProgressShouts;
    
    float Duration;
    float InitialProgress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    APlagueMeteor* meteor;
    AMeteorDefenseEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
 
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetMeteor(APlagueMeteor* NewMeteor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlagueMeteor* GetMeteor();
};
