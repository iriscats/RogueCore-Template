#pragma once
#include "CoreMinimal.h"
#include "CharacterShouts.generated.h"

class UDialogDataAsset;
USTRUCT(BlueprintType)
struct FCharacterShouts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* Attention;
    
    UDialogDataAsset* Follow;
    UDialogDataAsset* standingDown;
    UDialogDataAsset* Downed;
    UDialogDataAsset* RequestRevive;
    UDialogDataAsset* Revived;
    UDialogDataAsset* Resupply;
    UDialogDataAsset* FriendlyFire;
    UDialogDataAsset* KillCry;
    UDialogDataAsset* Dead;
    UDialogDataAsset* Cheating;
    UDialogDataAsset* ResourceFull;
    UDialogDataAsset* ResourceFullNoDonkey;
    UDialogDataAsset* CallDonkey;
    UDialogDataAsset* CallDonkey_NotInMission;
    UDialogDataAsset* Depositing;
    UDialogDataAsset* DepositingNoDonkey;
    UDialogDataAsset* OutOfAmmo;
    UDialogDataAsset* Reloading;
    UDialogDataAsset* CharacterSelected;
    UDialogDataAsset* UpgradeBought;
    UDialogDataAsset* WaitingInDropPod;
    UDialogDataAsset* Carrying;
    UDialogDataAsset* WaitingInEscapePod;
    UDialogDataAsset* Salute;
    UDialogDataAsset* Salute_Spacerig;
    UDialogDataAsset* Drink;
    UDialogDataAsset* Workout;
    ROGUECORE_API FCharacterShouts();
};
