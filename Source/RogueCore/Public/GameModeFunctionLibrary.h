#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameModeFunctionLibrary.generated.h"

class AActor;
class AFSDGameState;
class UObject;
class USeamlessTravelEventKey;
UCLASS(Blueprintable)
class UGameModeFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameModeFunctionLibrary();
 
    UFUNCTION(BlueprintCallable)
    static bool IsCloseToImportantLocation(AFSDGameState* GameState, const FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FTransform FindEscapePodLocationAtDistance(UObject* WorldContextObject, float Distance, float aboveDistanceBias, AActor* optionalFrom);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool AreAllMissionEndResultsReceived(const UObject* WorldContext);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddSeamlessTravelEventKey(UObject* WorldContextObject, USeamlessTravelEventKey* Key);
};
