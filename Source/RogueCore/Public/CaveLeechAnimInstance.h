#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "CaveLeechAnimInstance.generated.h"

class ACaveLeech;
class USceneComponent;
UCLASS(Blueprintable, NonTransient)
class UCaveLeechAnimInstance : public UAnimInstance {
    GENERATED_BODY()

public:
    UCaveLeechAnimInstance();

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeadOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACaveLeech* CaveLeech;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CaveLeechHead;

    FRotator BaseRotation;

    FVector BaseLocation;

    FVector HeadLocation;

    FRotator HeadRotation;

    bool bIdle;

    bool bTracking;

    bool bPulling;

    bool bRetracting;

    bool bDying;

    bool bDead;

    bool bFrozen;

    bool bImmobilized;

    bool bBiting;
};
