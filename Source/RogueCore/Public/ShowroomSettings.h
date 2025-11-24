#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShowroomSettings.generated.h"

class AShowroomStage;
class UCharacterShowroomController;
class UEnemyShowroomController;
class UPlanetShowroomController;
UCLASS(Blueprintable)
class UShowroomSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UEnemyShowroomController> EnemyShowroomController;
    
    TSoftClassPtr<UCharacterShowroomController> CharacterShowroomController;
    TSoftClassPtr<UPlanetShowroomController> PlanetShowroomController;
    TSoftClassPtr<AShowroomStage> CharacterStage;
    UShowroomSettings();
};
