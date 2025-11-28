#pragma once
#include "CoreMinimal.h"
#include "SpawnLogSubSection.h"
#include "SpawnLogSection.generated.h"

USTRUCT(BlueprintType)
struct FSpawnLogSection {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SectionHeader;
    
    TArray<FSpawnLogSubSection> SubSections;
    bool Expanded;
    ROGUECORE_API FSpawnLogSection();
};
