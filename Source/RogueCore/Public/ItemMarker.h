#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemMarker.generated.h"

UCLASS(Abstract, Blueprintable)
class AItemMarker : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMarkerValid;
    
    bool bMarkerVisible;
    AItemMarker(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMarkerVisibilityChanged(bool visible);
    void OnMarkerValidChanged(bool Valid);
};
