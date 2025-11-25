#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ZipLineConnector.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable)
class AZipLineConnector : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Character;
    
    FVector ZipLineLocation;
    FVector ZipLineDirection;
    FRotator RotationOffset;
    bool bSpeeding;
    AZipLineConnector(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUpdateZipLinePoint(const FVector& WorldLocation, const FVector& Directioy, bool Speeding);
    void ReceiveDisconnected();
    void ReceiveConnected(const FVector& WorldLocation, const FVector& Direction);
};
