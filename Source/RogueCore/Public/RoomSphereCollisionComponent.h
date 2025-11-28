#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "RoomSphereCollisionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URoomSphereCollisionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSphere RoomCheckSphere;
    
    URoomSphereCollisionComponent(const FObjectInitializer& ObjectInitializer);
};
