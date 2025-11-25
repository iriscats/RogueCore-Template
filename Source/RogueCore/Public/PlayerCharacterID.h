#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "PlayerCharacterID.generated.h"

class APlayerCharacter;
class UPlayerCharacterData;
UCLASS(Blueprintable)
class ROGUECORE_API UPlayerCharacterID : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AssetName;
    
    TSoftClassPtr<APlayerCharacter> Character;
    FString AnalyticsID;
    UPlayerCharacterData* CharacterData;
    UPlayerCharacterID();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidCharacterData() const;
    UPlayerCharacterData* GetCharacterData() const;
    TSubclassOf<APlayerCharacter> GetCharacterClass() const;
    APlayerCharacter* GetCharacterCDO() const;
};
