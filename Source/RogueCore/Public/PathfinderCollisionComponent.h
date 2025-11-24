#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/StaticMeshComponent.h"
#include "PFCollisionType.h"
#include "PathfinderCollisionComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPathfinderCollisionComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ActivatePFCollisionAtInit;
    
    PFCollisionType PFColiType;
    bool ShowInTerrainScanner;
    UPathfinderCollisionComponent(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void OnInitialGenerationDone();
    bool IsInsideConvex(FVector SamplePosition) const;
    void DisablePFCollision();
    void ActivatePFCollision();
};
