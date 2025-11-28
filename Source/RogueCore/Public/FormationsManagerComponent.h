#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FormationsManagerComponent.generated.h"

class UEnemySpawnManager;
class UFormationData;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFormationsManagerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemySpawnManager* SpawnManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFormationData*> FormationData;
    UFormationsManagerComponent(const FObjectInitializer& ObjectInitializer);
};
