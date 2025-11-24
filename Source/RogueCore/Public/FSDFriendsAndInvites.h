#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BlueprintFriend.h"
#include "EmptyFriendDelegateDelegate.h"
#include "FSDFriendsAndInvites.generated.h"

UCLASS(Blueprintable)
class UFSDFriendsAndInvites : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyFriendDelegate OnFriendsChanged;
    
    FEmptyFriendDelegate OnFriendInvitesChanged;
    FEmptyFriendDelegate OnRequestRefresh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintFriend> Friends;
    TArray<FBlueprintFriend> FriendInvites;
    UFSDFriendsAndInvites();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Init();
};
