#pragma once
#include "CoreMinimal.h"

#include "PlayerSphere.generated.h"

class APawn;
USTRUCT(BlueprintType)
struct FPlayerSphere {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector Center = FVector::ZeroVector;
    
    float Radius;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<APawn>> Players;

};
