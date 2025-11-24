#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "DisplayCaseDelegateDelegate.h"
#include "DisplayContent.h"
#include "DisplayCase.generated.h"

class UDialogDataAsset;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ADisplayCase : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USceneComponent* ContentAttachPoint;
    USkeletalMeshComponent* ContentMesh;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDisplayCaseDelegate OnContentUpdated;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve RelativeZOffset;
    FRuntimeFloatCurve ReactZOffsetCof;
    FRuntimeFloatCurve ReactTimeDilationCof;
    TArray<FDisplayContent> Contents;
    float RotationSpeed;
    float BeerMugSpawnChancePercent;
    float BarrelSpawnChancePercent;
    float TimeMultiplier;
    float SizeMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ContentIndex, meta=(AllowPrivateAccess=true))
    int32 ContentIndex;
    UDialogDataAsset* BeerMugShout;
    ADisplayCase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void RefreshContent();
    void PlayReactionAnimation();
    UFUNCTION()
    void OnRep_ContentIndex();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpecialContent() const;
    void InitializeCase();
    bool GetCurrentContent(FDisplayContent& currentContent) const;
    void ChangeContent();
};
