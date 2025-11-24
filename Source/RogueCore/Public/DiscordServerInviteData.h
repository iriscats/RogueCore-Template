#pragma once
#include "CoreMinimal.h"
#include "DiscordServerInviteGuildData.h"
#include "DiscordServerInviteData.generated.h"

USTRUCT(BlueprintType)
struct FDiscordServerInviteData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString code;
    
    int32 approximate_presence_count;
    int32 approximate_member_count;
    FDiscordServerInviteGuildData guild;
    ROGUECORE_API FDiscordServerInviteData();
};
