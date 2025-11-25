#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BossFightSubSystem.generated.h"

class AActor;
class IBossFightInterface;
class UBossFightInterface;
class UUserWidget;
UCLASS(Blueprintable)
class UBossFightSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCustomWidgetDelegate, UUserWidget*, InWidget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBossFightDelegate, const TScriptInterface<IBossFightInterface>&, BossFight);
    
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossFightDelegate OnNewBossFight;
    FBossFightDelegate OnBossFightRemoved;
    FCustomWidgetDelegate OnCustomWidgetAdded;
    FCustomWidgetDelegate OnCustomWidgetRemoved;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TScriptInterface<IBossFightInterface>> ActiveBossFights;
    UBossFightSubSystem();
    UFUNCTION(BlueprintCallable)
    void RemoveCustomBossFightWidget(UUserWidget* InWidget);
    void RegisterBossFight(TScriptInterface<IBossFightInterface> BossFight);
    void DeregisterBossFight(AActor* boss);
    void AddCustomBossFightWidget(UUserWidget* InWidget);
};
