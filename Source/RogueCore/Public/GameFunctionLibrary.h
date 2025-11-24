#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/NetSerialization.h"
#include "GameFunctionLibrary.generated.h"

class ADeepCSGWorld;
class AFSDGameMode;
class AFSDGameModeSpaceRig;
class AFSDGameState;
class AFSDWorldSettings;
class APlayerCharacter;
class UAsyncManager;
class UAudioComponent;
class UCampaignManager;
class UFSDGameInstance;
class UFSDSaveGame;
class UGameData;
class UObject;
class URunManager;
class USoundBase;
class UWindowManager;
class UWindowWidget;
UCLASS(Blueprintable)
class ROGUECORE_API UGameFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void SpawnOrUpdateAudio2D(UObject* WorldContext, UPARAM(Ref) UAudioComponent*& AudioComponent, USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier, FName FloatParamName, float FloatParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetUsePushToTalk(bool Enable);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetGlobalGravityZ(UObject* WorldContextObject, float GravityZ);
    static void SetGlobalGravityScale(UObject* WorldContextObject, float GravityScale);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsWorldTickEnabled(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsTearingDown(UObject* caller, bool& NewIsTearingDown);
    static bool IsPlayingOffline(UObject* WorldContextObject);
    static bool IsPlayInEditor(UObject* WorldContextObject);
    static UWindowManager* GetWindowManager(UObject* WorldContextObject);
    static bool GetUsePushToTalk();
    static UWindowWidget* GetTopWindow(UObject* WorldContextObject);
    static URunManager* GetRunManager(UObject* WorldContextObject);
    static FString GetProjectVersion();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static int32 GetNumPlayers(UObject* WorldContext);
    static int32 GetNumAdditionalPlayers(UObject* WorldContext);
    static FString GetMajorProjectVersion();
    static APlayerCharacter* GetLocalPlayerCharacter(UObject* WorldContext);
    static float GetGlobalGravityZ(UObject* WorldContextObject);
    static AFSDWorldSettings* GetFSDWorldSettings(UObject* WorldContextObject);
    static AFSDGameModeSpaceRig* GetFSDSRGameMode(UObject* WorldContextObject);
    static UFSDSaveGame* GetFSDSaveGame(UObject* WorldContextObject);
    static AFSDGameState* GetFSDGameState(UObject* WorldContextObject);
    static AFSDGameMode* GetFSDGameMode(UObject* WorldContextObject);
    static UFSDGameInstance* GetFSDGameInstance(UObject* WorldContextObject);
    static UGameData* GetFSDGameData();
    static float GetFrameRateInHz(UObject* WorldContextObject);
    static ADeepCSGWorld* GetCSGWorld(const UObject* WorldContextObject);
    static int32 GetChangelist();
    static UCampaignManager* GetCampaingManager(UObject* WorldContextObject);
    static UAsyncManager* GetAsyncManager(UObject* WorldContextObject);
    static bool EqualEqual_UniqueNetId(const FUniqueNetIdRepl& IdA, const FUniqueNetIdRepl& IdB);
};
