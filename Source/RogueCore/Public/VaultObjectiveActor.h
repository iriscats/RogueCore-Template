#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultObjectiveActor.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API AVaultObjectiveActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    USceneComponent* RootSceneComponent;

    

    AVaultObjectiveActor(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootSceneComponent;
    
    AVaultObjectiveActor(const FObjectInitializer& ObjectInitializer);
};
