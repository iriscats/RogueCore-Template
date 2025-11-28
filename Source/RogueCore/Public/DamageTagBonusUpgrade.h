#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "DamageTagBonusUpgrade.generated.h"

class UDamageTag;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UDamageTagBonusUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageTag*> Tags;
    
    UDamageTagBonusUpgrade();
};
