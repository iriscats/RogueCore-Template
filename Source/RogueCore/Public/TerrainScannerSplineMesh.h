#pragma once
#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "TerrainScannerSplineMesh.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTerrainScannerSplineMesh : public USplineMeshComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisibleAtBeginPlay;
    
    bool bHideOnDeath;
    bool bUseFogOfWar;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bVisibleOnScanner;
    UTerrainScannerSplineMesh(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetVisibleOnScanner(bool InShowOnScanner);
    void OnOwnerDeath(UHealthComponentBase* InHealthComponent);
};
