#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELaserPointerTargetType.h"
#include "LaserTerrainComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULaserTerrainComponent : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELaserPointerTargetType Type;
    
    ULaserTerrainComponent(const FObjectInitializer& ObjectInitializer);
};
