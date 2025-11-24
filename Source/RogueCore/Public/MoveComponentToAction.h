#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UnrealType.h"
#include "TickableActionBase.h"
#include "MoveComponentToAction.generated.h"

class UMoveComponentToAction;
class UObject;
class USceneComponent;
UCLASS(Blueprintable)
class UMoveComponentToAction : public UTickableActionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedDelegate, USceneComponent*, Component);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> Component;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompletedDelegate Completed;
    UMoveComponentToAction();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UMoveComponentToAction* EaseComponentTo(UObject* WorldContext, USceneComponent* InComponent, FTransform InEndTransform, TEnumAsByte<EEasingFunc::Type> InEasingMode, bool InWorldSpace, float InDuration);
};
