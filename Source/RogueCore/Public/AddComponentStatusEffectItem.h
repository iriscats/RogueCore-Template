#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "Templates/SubclassOf.h"
#include "AddComponentStatusEffectItem.generated.h"

class UActorComponent;
UCLASS(Blueprintable, EditInlineNew)
class UAddComponentStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorComponent> ComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> AddedComponent;
    UAddComponentStatusEffectItem();
};
