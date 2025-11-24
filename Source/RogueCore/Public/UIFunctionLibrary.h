#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UIFunctionLibrary.generated.h"

class UNewsTextLists;
class UObject;
class UPlayerCharacterID;
class UStageNameBank;
UCLASS(Blueprintable)
class UUIFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UUIFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void StartBugReporter();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetLoadoutIcon(UObject* WorldContextObject, UPlayerCharacterID* characterID, int32 loadoutIndex, int32 IconIndex);
    static void RemoveItemUINotification(UObject* WorldContextObject, TArray<UObject*> Item, bool MatchChildNotifications);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsInItemUINotificationSet(UObject* WorldContextObject, UObject* Item);
    UFUNCTION(BlueprintPure)
    static int64 GetUnixTimeStamp();
    static int32 GetLoadoutIcon(UObject* WorldContextObject, UPlayerCharacterID* characterID, int32 loadoutIndex);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FText> FormatNewsTexts(TArray<FText> texts, int32 RandomSeed, UNewsTextLists* wordList, UStageNameBank* MissionNameBank);
    static void ClearAllItemUINotifications(UObject* WorldContextObject);
    static void CheckItemUINotification(UObject* WorldContextObject, TArray<UObject*> Item, bool& HasNotification, bool MatchChildNotifications);
    static void AddItemUINotification(UObject* WorldContextObject, TArray<UObject*> Item);
};
