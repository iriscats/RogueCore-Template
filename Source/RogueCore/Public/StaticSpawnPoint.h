#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EStaticSpawnPointType.h"
#include "StaticSpawnPoint.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UStaticSpawnPoint : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsUsed;
    
    EStaticSpawnPointType Type;
    UStaticSpawnPoint(const FObjectInitializer& ObjectInitializer);
};
