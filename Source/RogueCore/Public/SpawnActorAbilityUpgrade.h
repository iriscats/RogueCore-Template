#pragma once
#include "CoreMinimal.h"

#include "AbilityUpgrade.h"
#include "Templates/SubclassOf.h"
#include "SpawnActorAbilityUpgrade.generated.h"

class AAbilitySpawnActor;
UCLASS(Blueprintable, EditInlineNew)
class USpawnActorAbilityUpgrade : public UAbilityUpgrade {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAbilitySpawnActor> SpawnActor;
    
    FVector SpawnLocationOffset;
    float Lifetime;
    USpawnActorAbilityUpgrade();
};
