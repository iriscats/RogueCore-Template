#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "LaserPointerWaypoint.generated.h"

class ALaserPointerItem;
class APlayerCharacter;
UCLASS(Abstract, Blueprintable)
class ALaserPointerWaypoint : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Character;
    
    TWeakObjectPtr<ALaserPointerItem> LaserPointer;
    FVector Normal;
    int32 Index;
    ALaserPointerWaypoint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShow();
    void OnHide();
};
