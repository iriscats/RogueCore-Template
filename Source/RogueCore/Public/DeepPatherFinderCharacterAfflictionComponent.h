#pragma once
#include "CoreMinimal.h"
#include "PawnAfflictionComponent.h"
#include "DeepPatherFinderCharacterAfflictionComponent.generated.h"

class ADeepPathfinderCharacter;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDeepPatherFinderCharacterAfflictionComponent : public UPawnAfflictionComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADeepPathfinderCharacter* Character;
    
    UDeepPatherFinderCharacterAfflictionComponent(const FObjectInitializer& ObjectInitializer);
};
