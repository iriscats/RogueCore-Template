#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocketAttacherComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USocketAttacherComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    int32 MaxSocketAttachments;

    

    USocketAttacherComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void DetachFromSocket();



public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSocketAttachments;
    
    USocketAttacherComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void DetachFromSocket();
    bool AttachToSocket(AActor* aTarget, FName SocketName, bool ShouldAttach);
};
