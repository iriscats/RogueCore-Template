#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "InstantUsable.h"
#include "UsersChangedDelegate.h"
#include "OncePerPlayerInstantUsableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UOncePerPlayerInstantUsableComponent : public UInstantUsable {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsersChanged OnUsersChangedEvent;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Users, meta=(AllowPrivateAccess=true))
    TArray<FUniqueNetIdRepl> ExcludedUsers;
    UOncePerPlayerInstantUsableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUsersChanged(const TArray<FUniqueNetIdRepl>& userList);
    UFUNCTION(BlueprintCallable)
    void OnRep_Users();
};
