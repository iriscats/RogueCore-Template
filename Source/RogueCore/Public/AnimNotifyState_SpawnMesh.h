#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_SpawnMesh.generated.h"

class UMaterialInstance;
class UStaticMesh;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_SpawnMesh : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* mesh;
    
    bool HasOverrideMaterial;
    UMaterialInstance* OverrideMaterial;
    int32 OverrideMaterialSlot;
    bool UseFirstPersonComponent;
    FName SocketName;
    FVector ScaleOverride;
    FVector LocationOffset;
    FRotator RotationOffset;
    UAnimNotifyState_SpawnMesh();
};
