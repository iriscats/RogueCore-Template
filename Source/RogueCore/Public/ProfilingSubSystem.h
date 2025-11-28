#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ProfileCategoryTiming.h"
#include "ProfileEntry.h"
#include "ProfilingSubSystem.generated.h"

UCLASS(Blueprintable)
class UProfilingSubSystem : public UWorldSubsystem {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FProfileEntry> Entries;
    
    UProfilingSubSystem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalTime() const;
    TArray<FProfileEntry> GetEntries() const;
    TArray<FProfileCategoryTiming> GetCategoryTimings() const;
};
