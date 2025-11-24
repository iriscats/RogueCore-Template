#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PloverTargetSockets.generated.h"

class UMeshComponent;
UCLASS(Blueprintable)
class UPloverTargetSockets : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Sockets;
    
    UPloverTargetSockets();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTargetSocket(UMeshComponent* mesh, FName& OutName) const;
};
