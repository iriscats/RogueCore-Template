#pragma once
#include "CoreMinimal.h"

#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Templates/SubclassOf.h"
#include "AnimNotify_SpawnActor.generated.h"

class AActor;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UAnimNotify_SpawnActor : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Actor;
    
    FName SocketName;
    FVector LocationOffset;
    FRotator RotationOffset;
    UAnimNotify_SpawnActor();
};
