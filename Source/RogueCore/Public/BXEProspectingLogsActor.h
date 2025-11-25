#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BXEProspectingLogsActor.generated.h"

class UBXEProspectingLogsObjective;
UCLASS(Blueprintable)
class ABXEProspectingLogsActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEProspectingLogsObjective* Objective;

 
    ABXEProspectingLogsActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void LogFound();
};
