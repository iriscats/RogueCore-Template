#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "DormantComponentState.generated.h"

class UActorComponent;
USTRUCT(BlueprintType)
struct FDormantComponentState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionEnabled::Type> Collision;
    FName CollisionProfileName;
    uint8 Active: 1;
    uint8 visible: 1;
    ROGUECORE_API FDormantComponentState();
};
