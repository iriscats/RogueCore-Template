#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpawnReleasedActor.generated.h"

class AActor;
UINTERFACE(Blueprintable)
class ROGUECORE_API USpawnReleasedActor : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ISpawnReleasedActor : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnSpawnRelease_Released(AActor* From);
    
    bool OnSpawnRelease_Attached(AActor* Parent);
};
