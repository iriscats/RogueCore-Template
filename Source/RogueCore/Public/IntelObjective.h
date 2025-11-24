#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "IntelObjective.generated.h"

class UIntelChallenge;
class UReward;
class UTexture2D;
UCLASS(Blueprintable)
class UIntelObjective : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText Description;
    UTexture2D* Icon;
    int32 RequiredIntel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UReward*> Rewards;
    TArray<TSubclassOf<UIntelChallenge>> Challenges;
    UIntelObjective();
};
