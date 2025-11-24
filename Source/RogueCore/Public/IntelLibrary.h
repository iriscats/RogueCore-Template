#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ERunDepth.h"
#include "IntelProgression.h"
#include "IntelLibrary.generated.h"

class UBiome;
class UIntelObjective;
class UObject;
class UStageComplexity;
class UStageDuration;
UCLASS(Blueprintable)
class UIntelLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UIntelLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStageDuration* GetUnlockedDuration(const UIntelObjective* IntelObjective);
    
    static ERunDepth GetUnlockedDepth(const UIntelObjective* IntelObjective);
    static UStageComplexity* GetUnlockedComplexity(const UIntelObjective* IntelObjective);
    static TArray<UBiome*> GetUnlockedBiomes(const UIntelObjective* IntelObjective);
    UFUNCTION(BlueprintCallable)
    static int32 ComputeUnlockedIntelPoints(const FIntelProgression& IntelProgress);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UIntelObjective*> ComputeUnlockableIntelObjectives(const UObject* WorldContext, const FIntelProgression& IntelProgress);
};
