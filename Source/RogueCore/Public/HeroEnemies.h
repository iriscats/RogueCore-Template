#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EliteEnemyEntry.h"
#include "StageLogic.h"
#include "HeroEnemies.generated.h"

class APawn;
class UEnemyDescriptor;
UCLASS(Abstract, Blueprintable)
class UHeroEnemies : public UStageLogic {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery AllowedQuery;
    
    TMap<UEnemyDescriptor*, FEliteEnemyEntry> Entries;
    UHeroEnemies();
    UFUNCTION(BlueprintCallable)
    void OnEnemySpawned(APawn* Enemy, UEnemyDescriptor* descriptor);
};
