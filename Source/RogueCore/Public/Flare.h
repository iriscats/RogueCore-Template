#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "FSDPhysicsActor.h"
#include "ItemIDInterface.h"
#include "LoadoutItem.h"
#include "SaveGameIDInterface.h"
#include "Templates/SubclassOf.h"
#include "UpgradableGear.h"
#include "Flare.generated.h"

class AActor;
class AFlare;
class AItem;
class UCurveFloat;
class UItemID;
class ULightComponent;
class USoundCue;
UCLASS(Abstract, Blueprintable, NoExport)
class AFlare : public AFSDPhysicsActor, public ISaveGameIDInterface, public IItemIDInterface, public ILoadoutItem, public IUpgradableGear {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialSpeed;
    
    float InitialAngularImpulse;
    float InitialAngularImpulseRandomScale;
    int32 MaxFlares;
    float ProductionTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Duration;
    FLinearColor ChromaColor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFlareOn, meta=(AllowPrivateAccess=true))
    bool IsFlareOn;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* DamageCauser;
    TSubclassOf<AActor> WeaponPreviewClass;
    TSubclassOf<AItem> LoadoutItem;
    UItemID* ItemID;
    USoundCue* ImpactGroundSound;
    AFlare(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StartLightFunction(ULightComponent* mainLight, TArray<ULightComponent*> spotLights, UCurveFloat* flutterCurve, UCurveFloat* fadeInCurve);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void SetCheckForClosePlayers(bool check);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateShadowRadius();
    UFUNCTION()
    void OnRep_IsFlareOn();
    void OnFlareSpawnCompleted();
    void OnFlareIgnite();
    void OnFlareExtinguish();
    void Inhibit();
    float ImmidiateFadeLight();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AActor> GetWeaponViewClass() const;
    static AFlare* GetFlareDefaultObject(TSubclassOf<AFlare> flareClass);
    void ActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    void ActivateFlare();
    // Fix for true pure virtual functions not being implemented
    TSubclassOf<AItem> GetLoadoutItemClass() const override PURE_VIRTUAL(GetLoadoutItemClass, return NULL;);
};
