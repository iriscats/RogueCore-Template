#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TerrainScannerStaticMesh.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTerrainScannerStaticMesh : public UStaticMeshComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    bool bVisibleOnScanner;

    UTerrainScannerStaticMesh(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void SetVisibleOnScanner(bool InShowOnScanner);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisibleAtBeginPlay;
    
    bool bHideOnDeath;
    bool bUseFogOfWar;
    bool bIsRevealedByDataTerminal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bVisibleOnScanner;
    UTerrainScannerStaticMesh(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetVisibleOnScanner(bool InShowOnScanner);
    void RegisterWithSubsystem();
    void OnOwnerDeath(UHealthComponentBase* InHealthComponent);
    void Initialize();
};
