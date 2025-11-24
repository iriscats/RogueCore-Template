#pragma once
#include "CoreMinimal.h"
#include "ObjectInfoComponent.h"
#include "SimpleObjectInfoData.h"
#include "Templates/SubclassOf.h"
#include "SimpleObjectInfoComponent.generated.h"

class UActorContextWidget;
class UDialogDataAsset;
class USceneComponent;
class UTexture2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USimpleObjectInfoComponent : public UObjectInfoComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InGameName;
    
    FText InGameDescription;
    UDialogDataAsset* LookAtShout;
    bool bHasMissionControlLookAtShout;
    UDialogDataAsset* MissionControlLookAtShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* LookAtShoutOverride;
    UTexture2D* Icon;
    UTexture2D* IconOverride;
    bool bIsPingableByLaserpointer;
    TSubclassOf<UActorContextWidget> ContextWidgetClass;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<USceneComponent>, FSimpleObjectInfoData> ComponentMap;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorContextWidget* ContextWidget;
    USimpleObjectInfoComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void SetInGameName(const FString& GameName);
    void SetInGameDescription(const FString& GameDescription);
    UFUNCTION(BlueprintCallable)
    void SetContextWidget(UActorContextWidget* InContextWidget);
    void OverrideLookAtShoutOrUseDefault(UDialogDataAsset* InShout);
    void OverrideLookAtShout(UDialogDataAsset* InShout);
    void OverrideIcon(UTexture2D* InTexture);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDialogDataAsset* GetDefaultLookAtShout() const;
    void ClearLookAtShoutOverride();
    void AddComponentObjectInfo(USceneComponent* TargetComponent, const FSimpleObjectInfoData& Data);
};
