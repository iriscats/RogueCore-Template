#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TutorialManager.generated.h"

class AFSDPlayerController;
class APlayerCharacter;
class UFSDSaveGame;
class UTutorialComponent;
UCLASS(Abstract, Blueprintable)
class ATutorialManager : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumTimeBetweenTutorials;
    
    bool ResetTutorialsOnStart;
    bool ShowTutorialsDebug;
    bool Disabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFSDPlayerController> PlayerController;
    TWeakObjectPtr<APlayerCharacter> PlayerCharacter;
    TWeakObjectPtr<UFSDSaveGame> SaveGame;
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UTutorialComponent>> Tutorials;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTutorialComponent> ActiveTutorial;
    ATutorialManager(const FObjectInitializer& ObjectInitializer);
};
