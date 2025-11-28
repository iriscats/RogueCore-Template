#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StageManager.generated.h"

class UStageLogic;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStageManager : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStageLogic*> RunningBlueprints;
    
    UStageManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnMatchStarted();
};
