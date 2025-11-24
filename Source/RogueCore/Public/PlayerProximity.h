#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerProximitySignatureDelegate.h"
#include "PlayerProximity.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerProximity : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDown;
    
    float Distance;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerProximitySignature OnPlayerProximity;
    UPlayerProximity(const FObjectInitializer& ObjectInitializer);
};
