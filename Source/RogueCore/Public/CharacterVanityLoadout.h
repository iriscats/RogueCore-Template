#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterVanityLoadout.generated.h"

USTRUCT(BlueprintType)
struct FCharacterVanityLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid EquippedHeadItemID;
    
    FGuid EquippedBeardItemID;
    FGuid EquippedArmorItemID;
    FGuid EquippedArmorMaterialID;
    FGuid EquippedBeardColorItemID;
    FGuid EquippedSkinColorItemID;
    FGuid EquippedEyebrowsItemID;
    FGuid EquippedMoustacheItemID;
    FGuid EquippedSideburnsItemID;
    bool UsingSleevelessArmor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 MedicalGownIndex;
    ROGUECORE_API FCharacterVanityLoadout();
};
