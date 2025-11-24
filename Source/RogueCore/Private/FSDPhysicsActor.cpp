#include "FSDPhysicsActor.h"
#include "UObject/UnrealType.h"

AFSDPhysicsActor::AFSDPhysicsActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    const FProperty* p_PhysicsReplicationMode = GetClass()->FindPropertyByName("PhysicsReplicationMode");
    (*p_PhysicsReplicationMode->ContainerPtrToValuePtr<EPhysicsReplicationMode>(this)) = EPhysicsReplicationMode::PredictiveInterpolation;
}


