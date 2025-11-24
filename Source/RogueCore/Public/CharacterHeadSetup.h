#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterHeadSetup.generated.h"

class USkeletalMesh;
UCLASS(Blueprintable)
class UCharacterHeadSetup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* DefaultHead;
    
    USkeletalMesh* NoHead;
    USkeletalMesh* HeadForMasks;
    USkeletalMesh* ThickNeck;
    USkeletalMesh* ThinNeck;
    USkeletalMesh* FlatEars;
    USkeletalMesh* FaceOnly;
    USkeletalMesh* EyesOnly;
    UCharacterHeadSetup();
};
