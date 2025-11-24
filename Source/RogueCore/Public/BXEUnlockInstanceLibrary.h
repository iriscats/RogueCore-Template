#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BXEUnlockInstance.h"
#include "EUnlockType.h"
#include "BXEUnlockInstanceLibrary.generated.h"

class UBXEUnlockRarity;
class UObject;
class UUnlockVisualSettings;
UCLASS(Blueprintable)
class UBXEUnlockInstanceLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBXEUnlockInstanceLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void PlayUnlockInstanceSelectedSound2D(const UObject* WorldContext, const FBXEUnlockInstance& UnlockInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UUnlockVisualSettings* GetUnlockInstanceVisualSettings(const FBXEUnlockInstance& UnlockInstance);
    static EUnlockType GetUnlockInstanceType(const FBXEUnlockInstance& UnlockInstance);
    static UBXEUnlockRarity* GetUnlockInstanceRarity(const FBXEUnlockInstance& UnlockInstance);
};
