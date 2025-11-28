#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "BoscoCarryingDetailComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBoscoCarryingDetailComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator CustomRotaion;
    
    UBoscoCarryingDetailComponent(const FObjectInitializer& ObjectInitializer);
};
