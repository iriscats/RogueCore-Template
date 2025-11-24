#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "SubsystemLoader.generated.h"

class USubsystem;
UCLASS(Blueprintable)
class USubsystemLoader : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<USubsystem>> BlueprintSubSystems;
    
    USubsystemLoader();
};
