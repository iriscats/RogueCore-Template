#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "ObjectInfoComponent.generated.h"

class APlayerController;
class UActorContextWidget;
class UDialogDataAsset;
class UPrimitiveComponent;
class UTexture2D;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UObjectInfoComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UObjectInfoComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool HasMissionControlLookAtShout(const UPrimitiveComponent* TargetComponent) const;
    
    UDialogDataAsset* GetMissionControlLookAtShout(const UPrimitiveComponent* TargetComponent) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDialogDataAsset* GetLookAtShout(const UPrimitiveComponent* TargetComponent) const;
    bool GetIsPingableByLaserpointer(const UPrimitiveComponent* TargetComponent) const;
    FText GetInGameName(const UPrimitiveComponent* TargetComponent) const;
    FLinearColor GetInGameIconTint(const UPrimitiveComponent* TargetComponent) const;
    UTexture2D* GetInGameIcon(const UPrimitiveComponent* TargetComponent) const;
    FText GetInGameDescription(const UPrimitiveComponent* TargetComponent) const;
    UActorContextWidget* GetContextWidget(APlayerController* InPlayerController);
};
