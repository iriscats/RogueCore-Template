#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DLCBase.h"
#include "SaveGameIDInterface.h"
#include "GameDLC.generated.h"

class UFileMediaSource;
class UObject;
class UResourceData;
class UTexture2D;
class UWindowWidget;
UCLASS(Blueprintable)
class UGameDLC : public UDLCBase, public ISaveGameIDInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFakeUnlockedStateInEditor;
    
    bool bEditorUnlockedState;
    int32 SteamID;
    FString SteamName;
    FString OddishID;
    FString XBoxDLCName;
    TMap<FString, FString> SonyAdditionalContentLabelMap;
    FString UWPStoreID;
    bool ShowOnDLCScreen;
    TSoftObjectPtr<UTexture2D> banner;
    TSoftObjectPtr<UTexture2D> Banner_16_9;
    TSoftObjectPtr<UTexture2D> InfoScreenOverlay;
    TSoftClassPtr<UWindowWidget> AnnouncementWidget;
    FGuid SavegameID;
    TMap<UResourceData*, int32> Resources;
    int32 PerformancePoints;
    TSoftObjectPtr<UFileMediaSource> Movie;
    UGameDLC();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool ShouldBeAnnounced(UObject* WorldContext) const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool OpenStorePage(UObject* WorldContext);
    void MarkAnnounced(UObject* WorldContext);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetSonyAdditionalContentId() const;
    UTexture2D* GetInfoScreenOverlay() const;
    UTexture2D* GetBanner_16_9() const;
    UTexture2D* GetBanner() const;
    // Fix for true pure virtual functions not being implemented
};
