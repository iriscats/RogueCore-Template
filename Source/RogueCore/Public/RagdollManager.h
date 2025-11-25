#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RagdollItem.h"
#include "RagdollManager.generated.h"

class AActor;
class UMaterialInstanceDynamic;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URagdollManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRagdollItem> Items;
    
    URagdollManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartRagdoll(AActor* Actor, const TArray<UMaterialInstanceDynamic*>& Materials, float desiredDuration);
};
