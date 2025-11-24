#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DynamicIcon.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UDynamicIcon : public UObject {
    GENERATED_BODY()
public:
    UDynamicIcon();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInterface* GetIconMaterial() const;
    
    UMaterialInstanceDynamic* GenerateIconMaterial(UObject* materialOwner) const;
};
