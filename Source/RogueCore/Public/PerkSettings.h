#pragma once
#include "CoreMinimal.h"
#include "PerkArray.h"
#include "PerkSettings.generated.h"

class UPerkAsset;
class UPlayerCharacterID;
USTRUCT(BlueprintType)
struct FPerkSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, FPerkArray> ClassPerks;
    
    UPerkAsset* IronWill;
    UPerkAsset* DashPerk;
    UPerkAsset* ShieldLink;
    UPerkAsset* Bezerk;
    UPerkAsset* JumpBoots;
    UPerkAsset* DownedBomb;
    UPerkAsset* FieldMedic;
    UPerkAsset* HeightenedSenses;
    UPerkAsset* HoverBoots;
    ROGUECORE_API FPerkSettings();
};
