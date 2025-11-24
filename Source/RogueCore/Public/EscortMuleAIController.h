#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AsyncPathRequestsInterface.h"
#include "FSDAIController.h"
#include "EscortMuleAIController.generated.h"

class UEscortObjective;
UCLASS(Blueprintable, NoExport)
class AEscortMuleAIController : public AFSDAIController, public IAsyncPathRequestsInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> CurrentPath;
    
    TArray<FVector> GaragePath;
    int32 PathIndex;
    int32 CurrentRoom;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEscortObjective* EscortObj;
    int32 TunnelStartIndex;
    int32 TunnelEndIndex;
    FRandomStream RandomStream;
    AEscortMuleAIController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetDozerNextPathSegment();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPathComplete();
    FVector GetPointBehindEscortMule(float Distance);
    TArray<FVector> GetPathForDebug(int32 Segment);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPathEndTagent();
    void GetFullPath(TArray<FVector>& OutPath) const;
    void FindDozerPath(FVector StartPosition);
    // Fix for true pure virtual functions not being implemented
};
