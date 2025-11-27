#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EndEffector.h"
#include "IKLegSetup.h"
#include "IKStyle.h"
#include "IKSyncGroup.h"
#include "IKComponent.generated.h"

class USphereComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIKComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    TArray<FIKLegSetup> LegSetups;
    TArray<FIKSyncGroup> SyncGroups;
    FIKStyle IKStyle;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* BodyColi;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEndEffector> Effectors;
    float EffectorWeight;
    bool EffectorsEnabled;
    UIKComponent(const FObjectInitializer& ObjectInitializer);
};
