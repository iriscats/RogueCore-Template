#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoolUserSettingAsset.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBoolUserSettingAsset : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SettingDisplayTitle;
    
    FName SettingID;
    bool SettingDefaultValue;
    UBoolUserSettingAsset();
    UFUNCTION(BlueprintCallable)
    void SetValue(bool InValue);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetValue() const;
};
