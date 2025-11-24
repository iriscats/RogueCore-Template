#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClassPerkLibrary.generated.h"

class UPerkAsset;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UClassPerkLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UClassPerkLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UPerkAsset*> GetAvailableClassPerks(const UPlayerCharacterID* Character);
    
};
