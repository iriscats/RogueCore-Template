#pragma once
#include "CoreMinimal.h"
#include "SkinEffect.h"
#include "SkeletalMeshSkinEffect.generated.h"

class USkeletalMesh;
UCLASS(Blueprintable, EditInlineNew)
class USkeletalMeshSkinEffect : public USkinEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;
    
    USkeletalMeshSkinEffect();
};
