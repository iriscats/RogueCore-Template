#pragma once
#include "CoreMinimal.h"
#include "ObjectInfoComponent.h"
#include "PlayerInfoComponent.generated.h"

class APlayerCharacter;
class UDialogDataAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPlayerInfoComponent : public UObjectInfoComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDialogDataAsset> LookAtShout;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UPlayerInfoComponent(const FObjectInitializer& ObjectInitializer);
};
