#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "DamageBonusUpgrade.generated.h"

class UDamageBonusBase;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UDamageBonusUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageBonusBase* DamageBonus;
    
    UDamageBonusUpgrade();
};
