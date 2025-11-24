#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaticSpawnPointManager.generated.h"

class UStaticSpawnPoint;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UStaticSpawnPointManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStaticSpawnPoint*> RegisteredSpawnPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsDirty;
    UStaticSpawnPointManager(const FObjectInitializer& ObjectInitializer);
};
