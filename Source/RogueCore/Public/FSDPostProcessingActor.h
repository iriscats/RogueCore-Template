#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Scene.h"
#include "EPostProcessingType.h"
#include "FSDPostProcessingActor.generated.h"

class APostProcessingManager;
class IBlendableInterface;
class UBlendableInterface;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UPostProcessComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AFSDPostProcessingActor : public AActor {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostProcessingType PostProcessingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* PostProcessComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeightedBlendables InitialBlendables;
    AFSDPostProcessingActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void UnapplyPostProcessingBlendablesByType(UObject* WorldContext, EPostProcessingType Type);
    static void UnapplyPostProcessingBlendablesByID(UObject* WorldContext, const FName InID);
    static void UnapplyPostProcessingBlendable(UObject* WorldContext, EPostProcessingType Type, TScriptInterface<IBlendableInterface> InBlendableObject);
    static void UnapplyAllPostProcessingBlendables(UObject* WorldContext);
    UFUNCTION(BlueprintCallable)
    void SetupHDRColorGamma();
    void SetPostProcessManager(APostProcessingManager* InManager);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UMaterialInstanceDynamic* GetPostProcessingMaterialInstance(UObject* WorldContext, UMaterialInterface* Material);
    static UMaterialInstanceDynamic* ApplyPostProcessingMaterial(UObject* WorldContext, EPostProcessingType Type, UMaterialInterface* Material, float InWeight, const FName InID);
    static void ApplyPostProcessingBlendable(UObject* WorldContext, EPostProcessingType Type, TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight, const FName InID);
};
