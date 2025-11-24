#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttachChangeSigDelegate.h"
#include "FSDPhysicsActor.h"
#include "OnCarriableDepositedDelegate.h"
#include "Throwable.h"
#include "CarriableItem.generated.h"

class AActor;
class APlayerCharacter;
UCLASS(Abstract, Blueprintable, NoExport)
class ACarriableItem : public AFSDPhysicsActor, public IThrowable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttachChangeSig OnAttachedChangeDelegate;

    FOnCarriableDeposited OnCarriableDeposited;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StrictDeposit;
    bool IsDopositable;
    ACarriableItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Throw(FVector Force);
    void Receive_OnDeposited(APlayerCharacter* fromPlayer, AActor* toActor);
    void OnAttachChanged(bool Attached);
    UFUNCTION(BlueprintCallable)
    void AttachChanged(bool Attached, const FVector& PrevScale);
    // Fix for true pure virtual functions not being implemented
};
