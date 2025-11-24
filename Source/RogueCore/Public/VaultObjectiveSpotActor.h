#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultObjectiveSpotActor.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API AVaultObjectiveSpotActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    USceneComponent* RootSceneComponent;

    

    AVaultObjectiveSpotActor(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RootSceneComponent;
    
    AVaultObjectiveSpotActor(const FObjectInitializer& ObjectInitializer);
};
