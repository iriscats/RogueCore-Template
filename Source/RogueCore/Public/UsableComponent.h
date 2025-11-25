#pragma once
#include "CoreMinimal.h"
#include "UsableComponentBase.h"
#include "UsedBySignatureDelegate.h"
#include "UsableComponent.generated.h"

class UDialogDataAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UUsableComponent : public UUsableComponentBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsedBySignature OnUsedByClient;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutBegin;
    FText UseText;
    bool ResetOnFail;
    bool SwitchToUsingState;
    UUsableComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetUseText(const FText& NewText);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDuration() const;
};
