#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "EItemCategory.h"
#include "AnimNotifyState_SpawnSkinnedMesh.generated.h"

class AItem;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_SpawnSkinnedMesh : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemCategory ItemCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AItem* Item;
    bool UseFirstPersonComponent;
    FName SocketName;
    FVector LocationOffset;
    FRotator RotationOffset;
    UAnimNotifyState_SpawnSkinnedMesh();
};
