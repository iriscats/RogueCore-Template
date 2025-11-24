#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IKControlCurveData.h"
#include "AnimCurveLockedIKComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAnimCurveLockedIKComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKControlCurveData> IKCurveControls;
    
    bool Debug;
    UAnimCurveLockedIKComponent(const FObjectInitializer& ObjectInitializer);
};
