#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "CompanionDroneInteractionPoint.h"
#include "CompanionDroneInteractable.generated.h"

class UCompanionDroneInteractionComponent;
UINTERFACE(Blueprintable, MinimalAPI)
class UCompanionDroneInteractable : public UInterface {
	GENERATED_BODY()
};
class ICompanionDroneInteractable : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetInteractionPoints(TArray<FCompanionDroneInteractionPoint>& interactionPoints);
    
    void GetInteractionLocation(TArray<FVector>& interactionPoints) const;
    UCompanionDroneInteractionComponent* GetInteractionComponent();
    void GetConnectorPoints(TArray<FTransform>& connectorPoints);
};
