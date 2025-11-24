#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ThrowParametersSimple.generated.h"

class APlayerCharacter;
class AThrowableActor;
USTRUCT(BlueprintType)
struct FThrowParametersSimple {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AThrowableActor> ThrownActorClass;
    
    APlayerCharacter* ThrowingCharacter;
    ROGUECORE_API FThrowParametersSimple();
};
