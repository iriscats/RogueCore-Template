#pragma once
#include "CoreMinimal.h"
#include "SingleUsableComponent.h"
#include "ConditionalUsableComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UConditionalUsableComponent : public USingleUsableComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AllowedActors;
    
    TArray<AActor*> IgnoredActors;
    UConditionalUsableComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveIgnored(AActor* ToRemove);
    void RemoveAllowed(AActor* ToRemove);
    void RemoveAllIgnored();
    void RemoveAllAllowed();
    void AddIgnored(AActor* ToIgnore);
    void AddAllow(AActor* ToAllow);
};
