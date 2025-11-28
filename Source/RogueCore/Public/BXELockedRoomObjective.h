#pragma once
#include "CoreMinimal.h"
#include "BXEBlueprintControlledObjective.h"
#include "Templates/SubclassOf.h"
#include "BXELockedRoomObjective.generated.h"

class AActor;
class ALockedRoomObjectiveSpawner;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBXELockedRoomObjective : public UBXEBlueprintControlledObjective {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ALockedRoomObjectiveSpawner> ObjectiveSpawner;
    
    float PercentOfPlayersForComplete;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PlayersInRoom, meta=(AllowPrivateAccess=true))
    int32 PlayersInRoom;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* LockedRoom;
    UBXELockedRoomObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool SetPlayersInRoom(const int32& Num);
    UFUNCTION()
    void OnRep_PlayersInRoom();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 NumOfPlayersForComplete() const;
    AActor* GetLockedRoom() const;
};
