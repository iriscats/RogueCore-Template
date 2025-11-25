#pragma once
#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "FSDWorldSettings.generated.h"

class UInventoryList;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class AFSDWorldSettings : public AWorldSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInventoryList* DebugInventoryList;
    
 
    UPlayerCharacterID* DefaultCharacterClass;
    UPlayerCharacterID* ClientCharacterClass;
    bool bSpawnInGameActors;
    AFSDWorldSettings(const FObjectInitializer& ObjectInitializer);
};
