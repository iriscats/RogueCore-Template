#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "JettyBootNPC.h"
#include "JettyBootsPlayer.h"
#include "JettyBootsReplay.h"
#include "JettyBootsSave.h"
#include "JettyBootsScore.h"
#include "JettyBootsArcadeActor.generated.h"

class APlayerCharacter;
class UAnimMontage;
class UJettyBootUsableComponent;
class USceneComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API AJettyBootsArcadeActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UJettyBootUsableComponent* StartGameUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Player, meta=(AllowPrivateAccess=true))
    FJettyBootsPlayer Player;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistanceToPlay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* MaxDistanceComponent;
    TArray<UAnimMontage*> AnimPlaying;
    TArray<UAnimMontage*> AnimFailed;
    TArray<UAnimMontage*> AnimSucces;
    TArray<FJettyBootNPC> HighScoreNPCs;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Save, meta=(AllowPrivateAccess=true))
    FJettyBootsSave JettyBootsSave;
    AJettyBootsArcadeActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetActivePlayer(APlayerCharacter* InPlayer);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ReplayPackage(const FJettyBootsReplay& InPackage);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveReplayPackage(const FJettyBootsReplay& InPackage);
    void ReceivePlayerChanged();
    void ReceiveHighScoreChanged();
    UFUNCTION(BlueprintCallable)
    void OnRep_Save();
    UFUNCTION()
    void OnRep_Player(const FJettyBootsPlayer& OldPlayer);
    void OnPlayerCharacterDestroyed(AActor* InActor);
    void OnCharacterMoved(float DeltaSeconds, FVector OldLocation, FVector OldVelocity);
    void OnCharacterMontageEnded(UAnimMontage* InMontage, bool InInterrupted);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerWithinDistance();
    int32 GetLastHighScoreIndex() const;
    TArray<FJettyBootsScore> GetHighScores() const;
    APlayerCharacter* GetActivePlayer() const;
    void ClearHighScores();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ReplayPackage(const FJettyBootsReplay& InPackage);
    void AddHighScoreServer(const FJettyBootsScore& InScore);
    void AddHighScoreClient(const FJettyBootsScore& InScore);
};
