#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "ItemLoadoutAnimations.h"
#include "Templates/SubclassOf.h"
#include "LoadoutItemProxy.generated.h"

class AActor;
class UItemCharacterAnimationSet;
UCLASS(Blueprintable)
class ALoadoutItemProxy : public AItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemCharacterAnimationSet* AnimationSet;
    
    FItemLoadoutAnimations LoadoutAnimations;
    ALoadoutItemProxy(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<AItem> GetLoadoutItemFromClass(TSubclassOf<AActor> ActorClass);
};
