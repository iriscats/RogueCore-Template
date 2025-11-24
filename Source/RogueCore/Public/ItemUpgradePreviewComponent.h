#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemUpgradePreviewComponent.generated.h"

class UItemUpgrade;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UItemUpgradePreviewComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemUpgradeDelegate, UItemUpgrade*, PreviewUpgrade);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemUpgradeDelegate OnPreviewUpgradeChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemUpgrade* PreviewUpgrade;
    UItemUpgradePreviewComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPreviewUpgrade(UItemUpgrade* InUpgrade);
    void RefreshPreviewUpgrade();
};
