#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AlignEnemyComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAlignEnemyComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RotateWhileStationary, meta=(AllowPrivateAccess=true))
    bool RotateWhileStationary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IncludePitch;
    UAlignEnemyComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRotateWhileStationary(bool Value);
    UFUNCTION(BlueprintCallable)
    void OnRep_RotateWhileStationary();
};
