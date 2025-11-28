#pragma once
#include "CoreMinimal.h"
#include "PerkEffectComponent.h"
#include "PerkEffectComponentKillNearby.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentKillNearby : public UPerkEffectComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> EnemyClass;
    
    UPerkEffectComponentKillNearby(const FObjectInitializer& ObjectInitializer);
};
