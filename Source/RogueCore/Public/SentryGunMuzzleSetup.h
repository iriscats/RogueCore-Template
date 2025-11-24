#pragma once
#include "CoreMinimal.h"
#include "SentryGunMuzzleSetup.generated.h"

class UAnimMontage;
USTRUCT(BlueprintType)
struct FSentryGunMuzzleSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UAnimMontage* FireMontage;
    ROGUECORE_API FSentryGunMuzzleSetup();
};
