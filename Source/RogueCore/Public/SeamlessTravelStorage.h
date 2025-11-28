#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/NetSerialization.h"
#include "PlayerDataStorage.h"
#include "SeamlessTravelStorage.generated.h"

class AActor;
class APlayerState;
class UDifficultySetting;
class UPlayer;
class UResourceData;
class USeamlessTravelEventKey;
UCLASS(Blueprintable)
class USeamlessTravelStorage : public UGameInstanceSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDifficultySetting* ChosenDifficulty;
    
    TMap<UPlayer*, bool> PlayerShouldStartInMedbay;
    TMap<UResourceData*, float> Resources;
    float MissionTime;
    TMap<FName, float> StoredFloatValues;
    TMap<FName, int32> StoredIntValues;
    TSet<USeamlessTravelEventKey*> EventKeys;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FUniqueNetIdRepl, FPlayerDataStorage> StoredPlayerData;
    TSet<AActor*> OtherStoredActors;
    TArray<APlayerState*> SeamlessTravelPlayerStates;
    USeamlessTravelStorage();
    UFUNCTION(BlueprintCallable)
    void UnStoreActor(AActor* Actor);
    void StoreActor(AActor* Actor);
    void ClearGameStateSeamlessTravelStorage();
};
