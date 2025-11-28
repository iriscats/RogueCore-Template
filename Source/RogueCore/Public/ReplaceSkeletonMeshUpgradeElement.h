#pragma once
#include "CoreMinimal.h"
#include "ItemUpgradeElement.h"
#include "ReplaceSkeletonMeshUpgradeElement.generated.h"

class UAnimInstance;
class USkeletalMesh;
UCLASS(Blueprintable, EditInlineNew)
class UReplaceSkeletonMeshUpgradeElement : public UItemUpgradeElement {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> TargetMesh;
    
    TSoftObjectPtr<USkeletalMesh> ReplaceWithMesh;
    TSoftClassPtr<UAnimInstance> ReplaceWithAnimInstance;
    UReplaceSkeletonMeshUpgradeElement();
};
