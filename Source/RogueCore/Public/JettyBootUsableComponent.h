#pragma once
#include "CoreMinimal.h"
#include "SingleUsableComponent.h"
#include "JettyBootUsableComponent.generated.h"

class APlayerCharacter;
class UMissionStat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UJettyBootUsableComponent : public USingleUsableComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CreditPrice;
    
    UJettyBootUsableComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool DeductCredits(APlayerCharacter* User, UMissionStat* InCreditCounter);
};
