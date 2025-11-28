#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "DamageData.h"
#include "EWeakpointGlowMode.h"
#include "WeakpointChannel.h"
#include "WeakpointGlowComponent.generated.h"

class UCurveFloat;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UMeshComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeakpointGlowComponent : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EmissiveParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWeakpointChannel> Channels;
    FRuntimeFloatCurve WeakpointHitCurve;
    float CurveMultiplier;
    EWeakpointGlowMode Mode;
    UFSDPhysicalMaterial* WeakPointMaterial;
    bool AddFirstChannelAutomatically;
    int32 ReplaceMatIndex;
    UWeakpointGlowComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool StopLoopingGlow(int32 aGlowID, bool aFade);
    void ShowBodypartHit(float amount, float BaseAmount, const FDamageData& DamageData);
    void SetUpWeakPointGlowOnMeshByBone(const USkeletalMeshComponent*& mesh, int32 MaterialIndex, FName bone, UHealthComponentBase* HealthComponent);
    int32 SetUpWeakPointGlowOnMesh(UMeshComponent* mesh, int32 MaterialIndex, UFSDPhysicalMaterial* PhysicalMaterial, UHealthComponentBase* HealthComponent);
    void SetChannelEnabled(bool Enabled, int32 Channel);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void EnableWeakpointRegistration(bool Enabled);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowWeakPointHit(uint8 Channel);
    void AddWeakpointGlow(bool loopIndefinitely, float LoopTime, UCurveFloat* GrowCurve, UCurveFloat* FadeCurve, int32 UniqueID, int32 Channel);
};
