#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyAnimInstance.h"
#include "PloverAnimInstance.generated.h"

class UDeepPathfinderMovement;
UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UPloverAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector MovementBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDeepPathfinderMovement> Movement;
    UPloverAnimInstance();
};
