#pragma once
#include "CoreMinimal.h"
#include "PawnAfflictionComponent.h"
#include "StaticObjectAfflictionComponent.generated.h"

class UStaticMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStaticObjectAfflictionComponent : public UPawnAfflictionComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* mesh;
    
    UStaticObjectAfflictionComponent(const FObjectInitializer& ObjectInitializer);
};
