#pragma once
#include "CoreMinimal.h"
#include "TextCounterEntry.h"
#include "TickableActionBase.h"
#include "MultiTextCounterAction.generated.h"

class UAudioComponent;
class UMultiTextCounterAction;
class UObject;
class USoundCue;
class UTextBlock;
UCLASS(Blueprintable)
class UMultiTextCounterAction : public UTickableActionBase {
    GENERATED_BODY()
    


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTickDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTickDelegate Completed;
    FTickDelegate OnTick;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTextBlock* TotalBlock;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText TotalFormat;
    TArray<FTextCounterEntry> Entries;
    float CountSpeed;
    USoundCue* CountingSound;
    UAudioComponent* AudioComponent;
    UObject* WorldContext;
    UMultiTextCounterAction();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContext"))
    static UMultiTextCounterAction* StartMultiTextCounter(UObject* InWorldContext, UTextBlock* InTotalBlock, const FText InTotalFormat, float InCountSpeed, USoundCue* InCountingSound, const TArray<FTextCounterEntry> InEntries);
};
