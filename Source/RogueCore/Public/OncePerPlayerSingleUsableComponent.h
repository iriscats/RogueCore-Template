#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "SingleUsableComponent.h"
#include "UsersChangedDelegate.h"
#include "OncePerPlayerSingleUsableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOncePerPlayerSingleUsableComponent : public USingleUsableComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsersChanged OnUsersChangedEvent;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Users, meta=(AllowPrivateAccess=true))
    TArray<FUniqueNetIdRepl> ExcludedUsers;
    UOncePerPlayerSingleUsableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUsersChanged(const TArray<FUniqueNetIdRepl>& userList);
    UFUNCTION(BlueprintCallable)
    void OnRep_Users();
};
