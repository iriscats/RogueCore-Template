#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CleaningPodLaunchedDelegate.h"
#include "EPlaceableObstructionType.h"
#include "PlaceableInterface.h"
#include "RessuplyPodItem.h"
#include "CleanupPodItem.generated.h"

class APlagueControlActor;
class APlagueInfectionNode;
UCLASS(Blueprintable, NoExport)
class ACleanupPodItem : public ARessuplyPodItem, public IPlaceableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCleaningPodLaunched OnCleaningPodLaunched;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlagueControlActor> PlagueController;
    ACleanupPodItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateWidget(EPlaceableObstructionType reason, float TimeLeft);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Call_CleaningPod(const FVector& Location, APlagueInfectionNode* plagueNode);
    UFUNCTION(BlueprintCallable)
    void CallUpdateWidget();
    // Fix for true pure virtual functions not being implemented
};
