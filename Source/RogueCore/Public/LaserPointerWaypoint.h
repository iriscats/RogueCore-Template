#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "LaserPointerWaypoint.generated.h"

class ALaserPointerItem;
class APlayerCharacter;
UCLASS(Abstract, Blueprintable, NoExport)
class ALaserPointerWaypoint : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

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
