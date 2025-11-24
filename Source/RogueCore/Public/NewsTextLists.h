#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NewsTextLists.generated.h"

UCLASS(Blueprintable)
class UNewsTextLists : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> Verb;
    
    TArray<FText> Person;
    TArray<FText> Creature;
    TArray<FText> Resource;
    TArray<FText> Minerals;
    TArray<FText> MineralFactions;
    UNewsTextLists();
};
