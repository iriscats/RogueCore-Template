#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PoseCorrectionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPoseCorrectionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    float FrontX;
    float SideY;
    float BackX;
    UPoseCorrectionComponent(const FObjectInitializer& ObjectInitializer);
};
