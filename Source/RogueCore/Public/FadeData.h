#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "FadeData.generated.h"

class UFSDLevelLoadingPersistentWidget;
class UTexture;
USTRUCT(BlueprintType)
struct FFadeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    bool bShowDebugOutput;
    TSubclassOf<UFSDLevelLoadingPersistentWidget> WidgetType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFSDLevelLoadingPersistentWidget* Widget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentFade;
    float TargetFade;
    float FadeSpeed;
    float Delay;
    bool bFadeWorldOnly;
    bool bCapFramerate;
    bool bToSpaceRig;
    UTexture* LoadingImage;
    FString DebugMsg;
    ROGUECORE_API FFadeData();
};
