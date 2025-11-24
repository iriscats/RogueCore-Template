#pragma once
#include "CoreMinimal.h"
#include "SeasonLevelWidget.h"
#include "SeasonInfinityLevelWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USeasonInfinityLevelWidget : public USeasonLevelWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InfinityStartLevel;
    
    USeasonInfinityLevelWidget();
};
