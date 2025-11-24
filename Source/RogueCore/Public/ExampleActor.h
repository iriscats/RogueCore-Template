#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleUpdatedDelegateDelegate.h"
#include "ExampleActor.generated.h"

UCLASS(Blueprintable, NoExport)
class AExampleActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExampleUpdatedDelegate OnExampleUpdated;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Field;

protected:
    AExampleActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ExampleFunction();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ExampleUpdated();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ExampleFunction();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ExampleFunction();
};
