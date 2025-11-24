#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "OldZiplineSalvage.generated.h"

class AZipLineProjectile;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AOldZiplineSalvage : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AZipLineProjectile> ZiplineProjectileClass;
    
protected:
    FVector RelativeDestinationLocation;
    AOldZiplineSalvage(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnMatchStarted();
};
