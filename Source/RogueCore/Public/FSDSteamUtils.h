#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ESteamBranch.h"
#include "FSDSteamUtils.generated.h"

class APlayerState;
UCLASS(Blueprintable)
class UFSDSteamUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDSteamUtils();
    UFUNCTION(BlueprintCallable)
    static void ResetSteamTicket();
    
    static bool PlayerIsFollowingUsOnSteam();
    static void OpenURLInSteamBrowser(const FString& URL);
    static void OpenSteamSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTextFilteringInitialized();
    static bool IsSteamLoaded();
    static bool IsDev(APlayerState* PlayerState);
    static bool InitializeFilterText();
    static bool HasSupporterUpgrade();
    static bool HasDeluxeEdition();
    static bool HasContentCreatorEdition();
    static FString GetSteamTicket();
    static FString GetSteamRegion();
    static FString GetSteamLanguage();
    static FString GetSteamBranchString();
    static ESteamBranch GetSteamBranch();
    static FString GetPlayerSteamName();
    static FString GetPlayerSteamID();
    static bool GenerateTokenIfNeeded();
    static FString FilterProfanityText(const FString& inputMessage);
};
