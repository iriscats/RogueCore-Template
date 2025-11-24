#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Curves/CurveFloat.h"
#include "GameplayTagContainer.h"
#include "ECharacterState.h"
#include "HeroInfo.h"
#include "Templates/SubclassOf.h"
#include "ActorFunctionLibrary.generated.h"

class AActor;
class AFSDGameMode;
class AFSDGameState;
class AFSDPlayerState;
class APlayerCharacter;
class APlayerController;
class IBlendableInterface;
class UBlendableInterface;
class UActorComponent;
class UEnemyComponent;
class UEnemyID;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UInventoryList;
class UItemID;
class UMaterialInstanceDynamic;
class UMeshComponent;
class UObject;
class UPathfinderCollisionComponent;
class UPlayerCharacterID;
class UPostProcessComponent;
class USceneComponent;
class USoundCue;
class UTexture2D;
class UUserWidget;
class UWindowWidget;
UCLASS(Blueprintable)
class ROGUECORE_API UActorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UActorFunctionLibrary();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void UnlockSpecificCharacters(TArray<APlayerCharacter*> Characters, ECharacterState UnlockIf, ECharacterState UnlockTo);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnlockCharacters(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float TimeSince(UObject* WorldContextObject, float Time);
    UFUNCTION(BlueprintCallable)
    static void SetScalarParameters(FName ParameterName, float Value, const TArray<UMaterialInstanceDynamic*>& Materials);
    static void PlayCueOnClient(APlayerController* Target, USoundCue* cue);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayCueOnAll(UObject* WorldContextObject, USoundCue* cue);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float PingPong(float Time, float Length, bool Normalize);
    static float MoveTowards(float Current, float End, float step);
    static void LockSpecificCharactersIfState(TArray<APlayerCharacter*> Characters, ECharacterState stateToLock);
    static void LockSpecificCharacters(TArray<APlayerCharacter*> Characters);
    static bool LockSpecificCharacterIfState(APlayerCharacter* Character, ECharacterState LockIf, ECharacterState LockTo);
    static void LockCharacters(UObject* WorldContextObject);
    static TSubclassOf<UWindowWidget> LoadWindowWidgetClass(TSoftClassPtr<UWindowWidget> WidgetClass);
    static TSubclassOf<UUserWidget> LoadWidgetClass(TSoftClassPtr<UUserWidget> WidgetClass);
    static UClass* LoadClass(TSoftClassPtr<UObject> SoftReference);
    static void KillActorWithEffects(AActor* Actor, USceneComponent* visualsToHide, USoundCue* deathSound, UFXSystemAsset* deathParticles, float particleScale, UPathfinderCollisionComponent* pathColliderToDisable);
    static bool IsWeakPoint(UFSDPhysicalMaterial* Material);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsSingleplayer(UObject* WorldContextObject);
    static bool IsMovingPlatform(AActor* Actor);
    static bool IsInRangeOfLocalPlayer(AActor* toActor, float MinDistance, float MaxDistance);
    static bool IsCloseToLocalPlayer(AActor* toActor, float Distance);
    static bool HasActorBegunPlay(const AActor* Actor);
    static int32 GetTotalHeroLevels(UObject* WorldContextObject, UPlayerCharacterID* characterID);
    static FGuid GetSaveGameIDFromCharacterID(UPlayerCharacterID* characterID);
    static FGuid GetSaveGameID(UClass* ObjectClass);
    static TArray<APlayerCharacter*> GetPlayersInRange(UObject* WorldContextObject, const FVector& Origin, float Radius, const bool allowClientUse, bool MustBeAlive);
    static TArray<APlayerCharacter*> GetPlayerCharactersThatAreAlive(const UObject* Context);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static APlayerCharacter* GetLocalPlayerCharacter(const UObject* WorldContext);
    static UItemID* GetItemID(TSubclassOf<AActor> itemClass);
    static float GetHeroXP(UObject* WorldContextObject, UPlayerCharacterID* characterID);
    static FText GetHeroSwitchToMessage(TSubclassOf<APlayerCharacter> playerClass);
    static FString GetHeroSourceName(TSubclassOf<APlayerCharacter> playerClass);
    static float GetHeroProgress(UObject* WorldContextObject, UPlayerCharacterID* characterID);
    static FText GetHeroName(TSubclassOf<APlayerCharacter> playerClass);
    static int32 GetHeroLevel(const UObject* WorldContextObject, UPlayerCharacterID* characterID);
    static UInventoryList* GetHeroInventoryList();
    static FHeroInfo GetHeroInfo(TSubclassOf<APlayerCharacter> playerClass);
    static UTexture2D* GetHeroImageSmall(TSubclassOf<APlayerCharacter> playerClass);
    static UTexture2D* GetHeroImageFullSize(TSubclassOf<APlayerCharacter> playerClass);
    static UTexture2D* GetHeroImage(TSubclassOf<APlayerCharacter> playerClass);
    static FLinearColor GetHeroColor(TSubclassOf<APlayerCharacter> playerClass);
    static UEnemyID* GetEnemyId(const AActor* Actor);
    static TArray<UActorComponent*> GetComponentsFromClass(TSubclassOf<AActor> Actor, const TSubclassOf<UActorComponent> ComponentClass);
    static UActorComponent* GetComponentFromClass(TSubclassOf<AActor> Actor, TSubclassOf<UActorComponent> ComponentClass);
    static UActorComponent* GetComponentByClass(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass);
    static UPlayerCharacterID* GetCharacterIDFromCharacter(APlayerCharacter* Character);
    static UPlayerCharacterID* GetCharacterID(TSubclassOf<APlayerCharacter> playerClass);
    static TArray<AFSDPlayerState*> GetAllPlayerStates(const UObject* WorldContext);
    static TArray<APlayerCharacter*> GetAllPlayerCharacters(const UObject* WorldContext);
    static FVector GetActorTargetCenter(const AActor* targetActor);
    static void FSDRemoveBlendable(UPostProcessComponent* PostProcessComponent, TScriptInterface<IBlendableInterface> InBlendableObject);
    static void FSDRemoveAllWidgets(UObject* WorldContextObject);
    static void FSDDumpCallStack(const FString& Msg);
    static APlayerCharacter* FindNearestPlayerCharacter(UObject* WorldContextObject, FVector fromLocation, float MaxRadius, bool MustBeAlive, bool MustBeUnparalyzed, bool MustHaveLineOfSight);
    static TArray<USceneComponent*> FindNearestComponents(const TArray<USceneComponent*>& ComponentsToCheck, const int32 AmountOfComponentsToFind, const FVector NearTo);
    static USceneComponent* FindNearestComponent(const TArray<USceneComponent*>& ComponentsToCheck, const FVector NearTo);
    static AActor* FindNearestActor(const TArray<AActor*>& ActorsToCheck, const FVector NearTo);
    static FVector FindLatejoinDroppodLocation(AFSDGameMode* GameMode);
    static AActor* FindClosestEnemyFromLocation(const FVector& fromLocation, float Range, bool LineOfSightCheck, UObject* WorldContextObject, const TArray<AActor*>& IgnoredActors, const FVector& Offset, bool onlyTargetable);
    static AActor* FindClosestEnemyFromActorWithSkipChance(AActor* FromActor, float Range, float SkipChance, bool LineOfSightCheck, const FGameplayTagQuery& TagQuery, FVector Offset);
    static AActor* FindClosestEnemyFromActor(AActor* FromActor, float Range, bool LineOfSightCheck, const FGameplayTagQuery& TagQuery, const FVector& Offset);
    static FVector FindCharacterTeleportLocation(UObject* WorldContextObject, const FVector& closeToLocation, float desiredDistance);
    static void FadeMaterials(const UObject* WorldContextObject, const UMeshComponent*& mesh, float Duration);
    static float EvaluateRuntimeCurve(UObject* WorldContextObject, const FRuntimeFloatCurve& Curve, float Time);
    static bool DoesActorHaveEnemyId(const AActor* Actor, const UEnemyID* EnemyID);
    static void DissolveMaterials(const UObject* WorldContextObject, const UMeshComponent*& mesh, float Duration);
    static TArray<UMaterialInstanceDynamic*> CreateDynamicMaterialInstances(UMeshComponent* mesh);
    static float AddHeroXP(UObject* WorldContextObject, UPlayerCharacterID* characterID, float amount);
    static void AddEnemyKill(APlayerCharacter* Instigator, UEnemyComponent* EnemyComponent, AFSDGameState* GameState);
    static bool ActorMatchesTagQuery(const FGameplayTagQuery& Query, const AActor* InActor);
};
