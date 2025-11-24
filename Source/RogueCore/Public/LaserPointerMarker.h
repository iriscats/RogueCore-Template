#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserPointerData.h"
#include "LaserPointerMarker.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable, NoExport)
class ALaserPointerMarker : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FLaserPointerData LookAtData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* LookAtActor;
    ALaserPointerMarker(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerCharacter* GetCharacter() const;
};
