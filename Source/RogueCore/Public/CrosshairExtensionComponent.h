#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "CrosshairExtensionComponent.generated.h"

class UCrosshairExtensionWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrosshairExtensionComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCrosshairExtensionWidgetDelegate, TSubclassOf<UCrosshairExtensionWidget>, WidgetClass, UCrosshairExtensionWidget*, Widget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCrosshairExtensionClassDelegate, TSubclassOf<UCrosshairExtensionWidget>, WidgetClass);
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCrosshairExtensionClassDelegate OnExtensionClassAddedDelegate;
    FCrosshairExtensionClassDelegate OnExtensionClassRemovedDelegate;
    FCrosshairExtensionWidgetDelegate OnExtensionCreatedDelegate;
    FCrosshairExtensionWidgetDelegate OnExtensionRemovedDelegate;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCrosshairExtensionWidget>> ExtensionClasses;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UCrosshairExtensionWidget>, UCrosshairExtensionWidget*> Extensions;
    UCrosshairExtensionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveExtensionClass(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass);
    void RemoveExtension(UCrosshairExtensionWidget* Widget);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UCrosshairExtensionWidget*> GetExtensions() const;
    TArray<TSubclassOf<UCrosshairExtensionWidget>> GetExtensionClasses() const;
    UCrosshairExtensionWidget* FindExtension(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass) const;
    void AddExtensionClass(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass);
    void AddExtension(UCrosshairExtensionWidget* Widget);
};
