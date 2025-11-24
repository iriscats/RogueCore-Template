#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "RandomizeComponent.generated.h"

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URandomizeComponent : public USceneComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldPickOne;
    
    float ChanceToBeOnPercent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    int32 SingleComponentKeepIndex;
    URandomizeComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
