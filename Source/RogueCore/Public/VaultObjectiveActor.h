#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultObjectiveActor.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AVaultObjectiveActor : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootSceneComponent;
    
    AVaultObjectiveActor(const FObjectInitializer& ObjectInitializer);
};
