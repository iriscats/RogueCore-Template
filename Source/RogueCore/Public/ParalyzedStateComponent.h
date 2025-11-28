#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "ParalyzedStateComponent.generated.h"

class AActor;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UParalyzedStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> CaveLeechClass;
    
    float CameraArmHeightOffset;
    float CameraArmSpeed;
    UParalyzedStateComponent(const FObjectInitializer& ObjectInitializer);
};
