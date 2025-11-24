#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "OnActivityEndedDelegateDelegate.h"
#include "OnActivityStartedDelegateDelegate.h"
#include "OnAnimationChangedDelegateDelegate.h"
#include "PersonalBestDelegateDelegate.h"
#include "BaseFitnessActivity.generated.h"

class AFitnessGym;
class APlayerCharacter;
class UArrowComponent;
class UPlayerCharacterID;
class USpringArmComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ABaseFitnessActivity : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActivityStartedDelegate OnActivityStarted;
    
    FOnActivityEndedDelegate OnActivityEnded;
    FPersonalBestDelegate OnPersonalBest;
    FOnAnimationChangedDelegate OnAnimationChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* ActorPlacement;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFitnessGym* OwnerGym;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, int32> HighScores;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    APlayerCharacter* CurrentUser;
    float CameraHorizontalLimits;
    float CameraVerticalLimits;
    TArray<USpringArmComponent*> CameraSpringArms;
    TArray<FTransform> CameraSpringArmsBaseTransforms;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentBestScore, meta=(AllowPrivateAccess=true))
    int32 CurrentBestScore;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentBestScoreName, meta=(AllowPrivateAccess=true))
    FString CurrentBestScoreName;
    int32 GymID;
    ABaseFitnessActivity(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StartActivity(APlayerCharacter* Player);
    void SetPersonalBest(int32 Best);
    void SetOwningGym(AFitnessGym* gym);
    UFUNCTION()

    void OnRep_CurrentBestScoreName() const;
    UFUNCTION()

    void OnRep_CurrentBestScore() const;
    APlayerCharacter* GetUserCharacter();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFitnessGym* GetOwnerGym() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ChangeVisibilityOfEquipment(bool Show);
};
