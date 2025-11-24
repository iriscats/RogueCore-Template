#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "FirstPersonStaticMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFirstPersonStaticMeshComponent : public UStaticMeshComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    bool EnabledFPFOV;

    

    UFirstPersonStaticMeshComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void SetEnabledFPFOV(bool FOV);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnabledFPFOV;
    
    UFirstPersonStaticMeshComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetEnabledFPFOV(bool FOV);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GeEnabledFPFOV() const;
};
