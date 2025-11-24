#pragma once
#include "CoreMinimal.h"
#include "WebBanner.generated.h"

USTRUCT(BlueprintType)
struct FWebBanner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ImageURL;
    
    FString TitleText;
    FString OnClickURL;
    int32 SteamID;
    ROGUECORE_API FWebBanner();
};
