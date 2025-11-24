#pragma once
#include "CoreMinimal.h"
#include "EFriendOnlineStatusEnum.h"
#include "BlueprintFriend.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintFriend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    FString RealName;
    EFriendOnlineStatusEnum OnlineStatus;
    FString UniqueNetId;
    ROGUECORE_API FBlueprintFriend();
};
