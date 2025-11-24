#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "EyeBrowsVanityItem.generated.h"

class USkeletalMesh;
class UVanityAnimInstance;
UCLASS(Blueprintable, EditInlineNew)
class UEyeBrowsVanityItem : public UVanityItem {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;

    TSoftClassPtr<UVanityAnimInstance> AnimInstance;

public:
    UEyeBrowsVanityItem();
};
