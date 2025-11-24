#pragma once
#include "CoreMinimal.h"
#include "DiscordServerInviteGuildData.generated.h"

USTRUCT(BlueprintType)
struct FDiscordServerInviteGuildData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString banner;
    
    FString Icon;
    FString splash;
    FString ID;
    FString Name;
    FString Description;
    ROGUECORE_API FDiscordServerInviteGuildData();
};
