#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "AttachedStateComponent.generated.h"

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAttachedStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableHeadLightOnEnter;
    
    bool EnableHeadLightOnExit;
 
    float MaxPitch;
    UAttachedStateComponent(const FObjectInitializer& ObjectInitializer);
};
