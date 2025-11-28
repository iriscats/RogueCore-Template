#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "SideburnsVanityItem.generated.h"

class USkeletalMesh;
class UVanityAnimInstance;
UCLASS(Blueprintable, EditInlineNew)
class USideburnsVanityItem : public UVanityItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;
    
    TSoftClassPtr<UVanityAnimInstance> AnimInstance;
    bool RequiresSlimArmor;
    USideburnsVanityItem();
};
