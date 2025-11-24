#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OnMinigamePopDelegateDelegate.h"
#include "OnMinigamePushedDelegateDelegate.h"
#include "SpaceRigSubSystem.generated.h"

class APlayerCharacter;
class UGymMinigameBaseWidget;
UCLASS(Blueprintable)
class ROGUECORE_API USpaceRigSubSystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    TArray<UGymMinigameBaseWidget*> MinigameHUDs;

    USpaceRigSubSystem();

    UFUNCTION(BlueprintCallable)

    void PushMiniGameWidget(APlayerCharacter* Owner, int32 Index);



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinigamePushedDelegate OnMiniGamePushed;
    
    FOnMinigamePopDelegate OnMiniGamePop;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGymMinigameBaseWidget*> MinigameHUDs;
    USpaceRigSubSystem();
    UFUNCTION(BlueprintCallable)
    void PushMiniGameWidget(APlayerCharacter* Owner, int32 Index);
    void PopMiniGameWidget(APlayerCharacter* Owner, int32 Index);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGymMinigameBaseWidget* GetMinigameHUD(uint8 Index) const;
    void AddMiniGameHUD(UGymMinigameBaseWidget* HUD);
};
