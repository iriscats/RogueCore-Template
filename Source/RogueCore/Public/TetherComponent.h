#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "ETetherConnectionMode.h"
#include "ETetherMessageDirection.h"
#include "TeherMessage_DelegateDelegate.h"
#include "TetherConnectionChanged_DeletageDelegate.h"
#include "TetherMessageSettings.h"
#include "TetherPowerChanged_DelegateDelegate.h"
#include "TetherRangeChangedDelegate.h"
#include "TetherComponent.generated.h"

class UMeshComponent;
class UTetherComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTetherComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTetherPowerChanged_Delegate OnPowerChanged;
    
    FTetherConnectionChanged_Deletage OnConnectionChanged;
    FTeherMessage_Delegate OnTetherMessage;
    FTetherRangeChanged OnConnectionRangeUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* TetherMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoSetup;
    TArray<UTetherComponent*> ConnectionHistory;
    FName ConnectionPointName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_ForwardConnection, meta=(AllowPrivateAccess=true))
    UTetherComponent* ForwardConnection;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_BackConnection, meta=(AllowPrivateAccess=true))
    TArray<UTetherComponent*> BackConnection;
    float ConnectionDistance;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ETetherConnectionMode ConnectionMode;
    int32 ConnectionPriority;
    int32 ConnectionHistorySize;
    int32 MaxBackwardConnections;
    bool GeneratesPower;
    bool PeriodicConnectionValidation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HasPower, meta=(AllowPrivateAccess=true))
    bool hasPower;
    UTetherComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ToggleConnectionValidation(bool Enabled, bool reactivate);
    void StopLoSTimer();
    void StartLoSTimer();
    void SetupConnectionpoint(UMeshComponent* mesh, const FName& SocketName);
    void SetConnectionRange(float Range);
    void ResetConnectionHistory();
    UFUNCTION()
    void OnRep_HasPower();
    UFUNCTION()
    void OnRep_ForwardConnection();
    UFUNCTION()
    void OnRep_BackConnection();
    void MessageTetherLine(const FName& Message, float Delay, ETetherMessageDirection messageDirection);
    void MessageBody(const FTetherMessageSettings& Message);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStartOfLine() const;
    bool IsFullyConnected() const;
    bool IsEndOfLine() const;
    bool IsConnected() const;
    UTetherComponent* GetTetherlineEnd(bool front);
    bool GetHasPower() const;
    UTetherComponent* GetForwardConnection();
    float GetConnectionRange() const;
    FVector GetConnectionPoint() const;
    TArray<UTetherComponent*> GetConnectionHistory();
    static bool DoesNetworkContainIntersection(UTetherComponent* Source, ETetherMessageDirection Direction);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DisconnectFromTetherLine(bool Deactivate);
    bool ConnectToTetherLine();
};
