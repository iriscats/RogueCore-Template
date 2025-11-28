#pragma once
#include "CoreMinimal.h"

#include "Templates/SubclassOf.h"
#include "ThrowParameters.generated.h"

class AActor;
class APlayerCharacter;
class AThrowableActor;
USTRUCT(BlueprintType)
struct FThrowParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AThrowableActor> ThrownActorClass;
    
    AActor* ThrownActorOwner;
    APlayerCharacter* ThrowingCharacter;
    FVector ThrowOrigin;
    float ThrowAngle;
    float ThrowerVelocityMultiplier;
    ROGUECORE_API FThrowParameters();
};
