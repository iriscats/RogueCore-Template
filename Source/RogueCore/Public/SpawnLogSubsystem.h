#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DelegateDelegate.h"
#include "SpawnLogSubsystem.generated.h"

class USpawnLogger;
UCLASS(Blueprintable)
class USpawnLogSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnLogAdded;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnLogger* CurrentLogger;
    TArray<USpawnLogger*> SpawnLoggers;
    USpawnLogSubsystem();
};
