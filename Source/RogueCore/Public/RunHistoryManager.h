#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DamageLogger.h"
#include "OnCharacterDataLoadedDelegate.h"
#include "ParsedRunHistoryEntry.h"
#include "RunHistoryBasicCooperStats.h"
#include "RunHistoryEntry.h"
#include "RunHistoryManager.generated.h"

class AFSDPlayerState;
class UCharacterBuildDataUtil;
class URun;
UCLASS(Blueprintable)
class ROGUECORE_API URunHistoryManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FDamageLogger Logger;

    bool HasSavedRecentRun;

    FRunHistoryBasicCooperStats BasicCooperStats;

    TMap<int32, FParsedRunHistoryEntry> CachedHistoryEntries;

    TMap<int32, FParsedRunHistoryEntry> SentPlayerStateEntries;

    URunHistoryManager();

    UFUNCTION(BlueprintCallable)

    void RemoveRunHistoryEntry(int32 Index);



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterDataLoaded OnCharacterDataLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCharacterBuildDataUtil* CharacterBuildDataUtil;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageLogger Logger;
    bool HasSavedRecentRun;
    FRunHistoryBasicCooperStats BasicCooperStats;
private:
    TMap<int32, FParsedRunHistoryEntry> CachedHistoryEntries;
    TMap<int32, FParsedRunHistoryEntry> SentPlayerStateEntries;
    URunHistoryManager();
    UFUNCTION(BlueprintCallable)
    void RemoveRunHistoryEntry(int32 Index);
    void OnRunGenerated(URun* Run);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FRunHistoryEntry> GetTotalRunHistory() const;
    bool GetParsedHistory(int32 HistoryIndex, FParsedRunHistoryEntry& OutEntry);
    bool GetLatestParsedHistory(FParsedRunHistoryEntry& OutEntry);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ClearDamageLog(UObject* WorldContext);
    void Cheat_SaveCurrentRunToHistory();
    void Cheat_ClearRunHistory();
    void AddCurrentRunToHistory(AFSDPlayerState* State);
};
