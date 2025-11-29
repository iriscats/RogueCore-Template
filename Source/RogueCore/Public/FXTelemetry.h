#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/UnrealType.h"
#include "FXTelemetry.generated.h"

class APlayerCharacter;
class UNetDriver;
class URun;
class UWorld;
UCLASS(Blueprintable)
class UFXTelemetry : public UGameInstanceSubsystem {
    GENERATED_BODY()
    

public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TelSessionID;
    
    FString TelRelativeEndpoint;
    FString TelTopic;
    UFXTelemetry();
    UFUNCTION(BlueprintCallable)
    void OnStageStart();
    void OnStageCompleted();
    void OnServerKickPlayer(const FString& KickReason);
    void OnRefreshRunData();
    void OnRefreshLivePlayerData(APlayerCharacter* Character);
    void OnNewRun(URun* Run);
    void OnNewCharacter(APlayerCharacter* Character);
    void OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, TEnumAsByte<ENetworkFailure::Type> failType, const FString& ErrorMessage);
    void OnLocalPlayerKicked(const FString& KickReason);
    void HandleCreateSessionComplete(FName SessionName, bool Successfull);
};
