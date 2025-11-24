#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TutorialComponent.generated.h"

class AFSDPlayerController;
class AFSDPlayerState;
class APlayerCharacter;
class ATutorialManager;
class UFSDSaveGame;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTutorialComponent : public UActorComponent {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTutorialEnabled;
    
    int32 Priority;
    float MaxDuration;
    int32 MaxViewCount;
    bool ShowInTutorialLevel;
    bool bAutoRegisterWithManager;
    bool bDebugAlwaysShow;
    bool ManuallyMarkViews;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> PlayerCharacter;
    TWeakObjectPtr<AFSDPlayerState> PlayerState;
    TWeakObjectPtr<AFSDPlayerController> PlayerController;
    TWeakObjectPtr<UFSDSaveGame> SaveGame;
    TWeakObjectPtr<ATutorialManager> TutorialManager;
    bool bTutorialInitialized;
    bool bTutorialReady;
    bool bTutorialVisible;
    bool bTutorialActive;
    UTutorialComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RegisterTutorial();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnShown();
    void ReceiveOnInitialized();
    void ReceiveOnHidden();
    void OnTutorialsReset();
    void OnManagerReady(ATutorialManager* manager);
    void MarkTutorialWatched();
    void MarkTutorialReadyNow();
    void MarkTutorialReadyInSeconds(float Delay);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTutorialBeenShown();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetTutorialName() const;
    void CancelTutorial(bool CountAsViewed);
};
