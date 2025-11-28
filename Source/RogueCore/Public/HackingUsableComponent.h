#pragma once
#include "CoreMinimal.h"
#include "HackingUsableState.h"
#include "InstantUsable.h"
#include "ItemDelegateDelegate.h"
#include "HackingUsableComponent.generated.h"

class AHackingToolItem;
class APlayerCharacter;
class UHackingToolWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UHackingUsableComponent : public UInstantUsable {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHackedDelegate, APlayerCharacter*, InHackedBy);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHackedDelegate OnHacked;
    FItemDelegate BeingHackedUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AHackingToolItem> ItemType;
    TSoftClassPtr<UHackingToolWidget> HackingWidgetType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HackingState, meta=(AllowPrivateAccess=true))
    FHackingUsableState HackingState;
    UHackingUsableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_HackingState(const FHackingUsableState& oldState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsHacked() const;
    bool GetIsBeingHacked() const;
    TSoftClassPtr<UHackingToolWidget> GetHackingWidgetType() const;
    APlayerCharacter* GetHackedBy() const;
};
