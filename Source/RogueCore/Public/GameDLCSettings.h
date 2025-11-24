#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameDLCSettings.generated.h"

class UGameDLC;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API UGameDLCSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UGameDLC*> StoreDLCs;

    UGameDLCSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    TArray<UGameDLC*> GetStoreDLCs(UObject* WorldContext);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    TArray<UGameDLC*> GetAnnouncableDLCs(UObject* WorldContext);

};
