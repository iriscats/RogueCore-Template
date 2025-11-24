#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackerPositioningComponent.h"
#include "EscortMuleAttackerPositioning.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEscortMuleAttackerPositioning : public UAttackerPositioningComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TArray<FVector> AttackerPositions;

    UEscortMuleAttackerPositioning(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void SetNewMaxAttackers(int32 newMaxAttackers);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponentBase* Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> AttackerPositions;
    UEscortMuleAttackerPositioning(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetNewMaxAttackers(int32 newMaxAttackers);
    void SetCostModifier(float Modifier);
};
