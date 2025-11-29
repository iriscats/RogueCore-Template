#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterBuildData.h"
#include "CharacterDamageData.h"
#include "ERunHistoryNetMessageDataType.h"
#include "OnBuildDataReceivedDelegate.h"
#include "OnDamageDataReceivedDelegate.h"
#include "OnRunHistoryDataReceivedDelegate.h"
#include "OnSharedRunDataReceivedDelegate.h"
#include "ParsedCharacterBuildData.h"
#include "ParsedCharacterDamageData.h"
#include "RunHistoryEntry.h"
#include "RunHistoryNetMessage.h"
#include "SharedRunData.h"
#include "RunHistoryStateComponent.generated.h"

class AFSDPlayerState;
class URunHistoryStateComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API URunHistoryStateComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBuildDataReceived OnBuildDataReceived;
    
    FOnDamageDataReceived OnDamageDataReceived;
    FOnSharedRunDataReceived OnSharedRunDataReceived;
    FOnRunHistoryDataReceived OnRunHistoryDataReceived;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FParsedCharacterBuildData> CachedParsedBuildData;
    TArray<FParsedCharacterDamageData> CachedParsedDamageData;
    TArray<FCharacterBuildData> CachedBuildData;
    TArray<FCharacterDamageData> CachedDamageData;
    FSharedRunData CachedSharedData;
    FRunHistoryEntry CachedRunHistoryEntry;
    TArray<FRunHistoryNetMessage> NetMessages;
    TMap<URunHistoryStateComponent*, bool> ActiveMessageListeners;
    TArray<uint8> ReceivingBuffer;
    URunHistoryStateComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RequestHistoryData(URunHistoryStateComponent* Sender, AFSDPlayerState* TargetState, ERunHistoryNetMessageDataType Type);
    UFUNCTION(BlueprintCallable)
    void RequestBuildData(AFSDPlayerState* TargetState);
    bool GetLatestDamageData(int32 PlayerId, FParsedCharacterDamageData& OutData);
    bool GetLatestBuildData(int32 PlayerIndex, FParsedCharacterBuildData& OutData);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ReceiveDataDone(ERunHistoryNetMessageDataType Type, int32 TargetPlayerIndex);
    void Client_ReceiveData(const TArray<uint8>& CharacterData);
};
