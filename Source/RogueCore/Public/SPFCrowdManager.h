#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPFCrowdManager.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ASPFCrowdManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AllSPFActors;
    
    ASPFCrowdManager(const FObjectInitializer& ObjectInitializer);
};
