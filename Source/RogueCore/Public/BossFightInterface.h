#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "BossFightInterface.generated.h"

class AActor;
class UBossFightWidget;
UINTERFACE(Blueprintable)
class ROGUECORE_API UBossFightInterface : public UInterface {
	GENERATED_BODY()
};

class ROGUECORE_API IBossFightInterface : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsStillValid();
    
    TSubclassOf<UBossFightWidget> GetWidgetClass();
    AActor* GetBossActor();
};