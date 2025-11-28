#pragma once
#include "CoreMinimal.h"
#include "SpawnLogSubSection.generated.h"

USTRUCT(BlueprintType)
struct FSpawnLogSubSection {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SectionHeader;
    
    TArray<FString> log;
    bool Expanded;
    ROGUECORE_API FSpawnLogSubSection();
};
