#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorUsableDelegateDelegate.h"
#include "EInputKeys.h"
#include "UsableComponentBase.generated.h"

class APlayerCharacter;
class UAccessCondition;
class USceneComponent;
class UTexture2D;
class UUseAnimationSetting;
class UUseConditionSet;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UUsableComponentBase : public UActorComponent {
    GENERATED_BODY()
    
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUsableHoveredEvent, APlayerCharacter*, InUser);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsableHoveredEvent OnHovered;
    FUsableHoveredEvent OnUnhovered;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CallbackKeys;
    FActorUsableDelegate OnUseDenied;
 
    float UseCooldown;
    UUseAnimationSetting* AnimationSettings;
    int32 Priority;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* RestrictToCollider;
    bool UsableHidesPlaceables;
    bool IsRayTraceTriggered;
    bool ResetUsingOnCompletion;
    UUseConditionSet* UseConditions;
    UAccessCondition* AccessCondition;
    bool IsClientPredictive;
    bool ThirdPersonWhileUsing;
    bool CapitalUseText;
    TWeakObjectPtr<APlayerCharacter> HoveringPlayer;
    UUsableComponentBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetUseRestrictions(UUseConditionSet* Set);
    void SetRayTraceTriggered(bool rayTraceTriggered);
    void SetAnimationSettings(UUseAnimationSetting* Settings);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetUseText(APlayerCharacter* User);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUseProgressInPercent(APlayerCharacter* User) const;
    UTexture2D* GetUsableIcon() const;
    bool GetShowUsingUI() const;
    bool GetIsRayTraceTriggerd() const;
    bool GetIsHovered() const;
    APlayerCharacter* GetHoveredBy() const;
    bool GetHideProgressBar(APlayerCharacter* User) const;
    bool GetHideActionText(APlayerCharacter* User) const;
    bool GetCapitalUseText() const;
    UAccessCondition* GetAccessCondition() const;
    void EndUse(APlayerCharacter* User);
    void BeginUse(APlayerCharacter* User, EInputKeys Key);
};
