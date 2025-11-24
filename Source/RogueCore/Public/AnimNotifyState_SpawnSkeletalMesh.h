#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_SpawnSkeletalMesh.generated.h"

class UAnimSequenceBase;
class USkeletalMesh;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_SpawnSkeletalMesh : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* mesh;
    
    UAnimSequenceBase* AnimationToPlay;
    bool UseFirstPersonComponent;
    FName SocketName;
    FVector ScaleOverride;
    FVector LocationOffset;
    FRotator RotationOffset;
    UAnimNotifyState_SpawnSkeletalMesh();
};
