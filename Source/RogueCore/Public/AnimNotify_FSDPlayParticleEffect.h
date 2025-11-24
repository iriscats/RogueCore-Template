#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_FSDPlayParticleEffect.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_FSDPlayParticleEffect : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* PSTemplate;
    
    FVector LocationOffset;
    FRotator RotationOffset;
    bool AlwaysZUp;
    FVector Scale;
    uint8 Attached: 1;
    FName SocketName;
    bool IsFirstPerson;
    bool UseTerainMaterial;
    UAnimNotify_FSDPlayParticleEffect();
};
