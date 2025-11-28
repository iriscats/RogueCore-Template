#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "ItemIDInterface.h"
#include "LoadoutItem.h"
#include "SaveGameIDInterface.h"
#include "Templates/SubclassOf.h"
#include "Grenade.generated.h"

class AGrenade;
class AItem;
class ALoadoutItemProxy;
class UFXSystemAsset;
class UGrenadeAnimationSet;
class UGrenadeProjectionSettings;
class UItemID;
class UProjectileMovementComponent;
class USoundCue;
class UStaticMesh;
class UUpgradeContainerComponent;
class UUserWidget;
UCLASS(Blueprintable)
class AGrenade : public AActor, public ISaveGameIDInterface, public IItemIDInterface, public ILoadoutItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> CrossHairType;
    
    FRotator ThrowDirectionOffset;
    TArray<FVector2D> CookTickTimeline;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent* Movement;
    UUpgradeContainerComponent* UpgradeContainer;
    UGrenadeProjectionSettings* ProjectionSettings;
    USoundCue* CookingSound;
    UStaticMesh* HandAttachMesh;
    UItemID* ItemID;
    USoundCue* ImpactGroundSound;
    UFXSystemAsset* ImpactGroundParticles;
    UGrenadeAnimationSet* GrenadeAnimationSetOverride;
    TSubclassOf<AActor> WeaponPreviewClass;
    TSubclassOf<ALoadoutItemProxy> LoadoutProxy;
    float CoolDown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Duration;
    float cookTime;
    float ExplosionDelay;
    bool IsReturningToSender;
    int32 MaxGrenades;
    bool CanCook;
    bool ExplodeOnImpact;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HasExploded, meta=(AllowPrivateAccess=true))
    bool HasExploded;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CountDownBegun;
    float RemainingDuration;
    AGrenade(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_HasExploded();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExploded();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNonFriendlyPawn(AActor* Actor) const;
    bool IsNonFriendly(AActor* Actor) const;
    TSubclassOf<AActor> GetWeaponViewClass() const;
    static AGrenade* GetGrenadeDefaultObject(TSubclassOf<AGrenade> GrenadeClass);
    void CopyUpgradeFromGrenade(AActor* To);
    void ActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    // Fix for true pure virtual functions not being implemented
    TSubclassOf<AItem> GetLoadoutItemClass() const override PURE_VIRTUAL(GetLoadoutItemClass, return NULL;);
};
