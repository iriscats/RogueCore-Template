#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActorContextWidget.generated.h"

class AActor;
class UPrimitiveComponent;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UActorContextWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ContextActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* ContextPrimitive;
    UActorContextWidget();
    UFUNCTION(BlueprintCallable)
    void Update(UPrimitiveComponent* InContextPrimitive);
    void Show(UPrimitiveComponent* InContextPrimitive);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUpdate(UPrimitiveComponent* InContextPrimitive);
    void ReceiveShow(UPrimitiveComponent* InContextPrimitive);
    void ReceiveContextActorChanged(AActor* InContextActor);
};
