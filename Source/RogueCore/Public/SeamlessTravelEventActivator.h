#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SeamlessTravelEventActivator.generated.h"

class USeamlessTravelEventKey;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USeamlessTravelEventActivator : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USeamlessTravelEventKey* EventKey;
    
    USeamlessTravelEventActivator(const FObjectInitializer& ObjectInitializer);
};
