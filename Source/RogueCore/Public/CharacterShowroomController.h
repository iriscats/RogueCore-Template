#pragma once
#include "CoreMinimal.h"
#include "EItemCategory.h"
#include "ShowroomController.h"
#include "Templates/SubclassOf.h"
#include "CharacterShowroomController.generated.h"

class AItem;
class APlayerCharacter;
class UCharacterShowroomController;
class UObject;
class UPlayerCharacterID;
class UShowroomCameraKey;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterShowroomController : public UShowroomController {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* CharacterInstance;
    
    UCharacterShowroomController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_CharacterShown();
    void EquipWeaponFromItem(TSubclassOf<AItem> Item);
    void EquipWeapon(EItemCategory Category);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UCharacterShowroomController* DisplayCharacter(UObject* WorldContextObject, UPlayerCharacterID* characterID, UShowroomCameraKey* Key, UShowroomCameraKey* zoomInKey, UShowroomCameraKey* zoomOutKey);
};
