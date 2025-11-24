#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "TerrainScannerItem.generated.h"

class UAnimMontage;
class USceneCaptureComponent2D;
class USceneComponent;
UCLASS(Blueprintable, NoExport)
class ATerrainScannerItem : public AAnimatedItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TerrainScannerZoomDirection;
    
    FName ScannerAttachSocketName;
    float TerrainScannerStartAngle;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TerrainScannerScale;
    float DelayedTerrainScannerScale;
    float DelayedTerrainScannerZoom;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsLookingAtMap, meta=(AllowPrivateAccess=true))
    bool IsLookingAtMap;
    bool UpdateMapToolActors;
    TArray<UAnimMontage*> UseLoopsFP;
    UAnimMontage* EndFP;
    TArray<UAnimMontage*> UseLoopsTP;
    UAnimMontage* EndTP;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TerrainScannerRoot;
    USceneCaptureComponent2D* TerrainScannerCapture;
    ATerrainScannerItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIslookingAtMap(bool lookingAtMap);
    UFUNCTION(BlueprintCallable)
    void OnRep_IsLookingAtMap();
};
