#pragma once
#include "CoreMinimal.h"
#include "TutorialComponent.h"
#include "TutorialHint.h"
#include "TutorialHintComponent.generated.h"

class UObject;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTutorialHintComponent : public UTutorialComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialHint Hint;
    
    UTutorialHintComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetRemainingVisibleTime(float remainingTime);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsSingleplayer(UObject* WorldContext) const;
    void ChangeHint(const FTutorialHint& NewHint);
};
