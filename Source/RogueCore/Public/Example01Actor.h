#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetChangedDelegateDelegate.h"
#include "Example01Actor.generated.h"

class UExample01ActorComponent;
class UStaticMesh;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AExample01Actor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetChangedDelegate OnTargetChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExample01ActorComponent* ExampleComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Mesh, meta=(AllowPrivateAccess=true))
    UStaticMesh* mesh;

 
    AExample01Actor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TargetChangedCallback(AActor* NewTarget);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTarget(AActor* NewTarget);
    void SetMesh(UStaticMesh* NewMesh);
    UFUNCTION()
    void OnRep_Mesh();
};
