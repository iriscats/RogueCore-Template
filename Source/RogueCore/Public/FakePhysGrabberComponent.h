#pragma once
#include "CoreMinimal.h"
#include "AvoidActorEntry.h"
#include "GrabAvoidClassEntry.h"
#include "GrabberComponent.h"
#include "FakePhysGrabberComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFakePhysGrabberComponent : public UGrabberComponent {
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGrabAvoidClassEntry> ActorTypesToAvoid;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAvoidActorEntry> ActorsToAvoid;

private:
    UFakePhysGrabberComponent(const FObjectInitializer& ObjectInitializer);
};
