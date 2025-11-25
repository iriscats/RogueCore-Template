#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaveObject.generated.h"

UCLASS(Abstract, Blueprintable, NoExport)
class ACaveObject : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanCharacterStandOn;
 
    
    ACaveObject(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerNetworkUpdate();
    void ResumeNetworkUpdates();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void Recieve_OnGameStarted();
    void PauseNetworkUpdates();
};
