#pragma once
#include "CoreMinimal.h"
#include "AttackerPositioningComponent.h"
#include "ObjectAttackerPositioning.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UObjectAttackerPositioning : public UAttackerPositioningComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponentBase* Health;
    
    UObjectAttackerPositioning(const FObjectInitializer& ObjectInitializer);
};
