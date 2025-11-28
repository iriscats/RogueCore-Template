#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectiveMissionIcon.h"
#include "SavableDataAsset.h"
#include "StageTemplate.generated.h"

class AFSDGameMode;
class UFSDSaveGame;
class UStageTemplate;
class UTexture2D;
class UTutorialComponent;
class UWorld;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UStageTemplate : public USavableDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StageName;
    
    TSoftObjectPtr<UWorld> Level;
    TSoftClassPtr<AFSDGameMode> GameMode;
    UTexture2D* StageIcon;
    UTexture2D* StageIconSmall;
    FLinearColor StageColor;
    int32 StageTypeIndex;
    TArray<TSoftClassPtr<UTutorialComponent>> Tutorials;
    UStageTemplate();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked(UFSDSaveGame* SaveGame) const;
    int32 GetStageTypeIndex() const;
    UTexture2D* GetStageImageLarge() const;
    UTexture2D* GetStageButtonImage() const;
    static FObjectiveMissionIcon GetPrimaryObjectiveIconFromAsset(UStageTemplate* Mission, bool getSmallVersion);
    FObjectiveMissionIcon GetPrimaryObjectiveIcon(bool getSmallVersion) const;
};
