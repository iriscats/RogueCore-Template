#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "PushingState.generated.h"

class UUseAnimationSetting;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPushingState : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUseAnimationSetting* PushingAnimation;
    
    UPushingState(const FObjectInitializer& ObjectInitializer);
};
