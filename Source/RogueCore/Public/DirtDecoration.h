#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirtQueryResult.h"
#include "DirtDecoration.generated.h"

UCLASS(Blueprintable)
class ADirtDecoration : public AActor {
    GENERATED_BODY()
public:
    ADirtDecoration(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveDirtQueryResult(const FDirtQueryResult& InQueryResult);
    
};
