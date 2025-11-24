#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DelegateDelegate.h"
#include "SpawnLogSubsystem.generated.h"

class USpawnLogger;
UCLASS(Blueprintable)
class USpawnLogSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnLogAdded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnLogger* CurrentLogger;
    TArray<USpawnLogger*> SpawnLoggers;
    USpawnLogSubsystem();
};
