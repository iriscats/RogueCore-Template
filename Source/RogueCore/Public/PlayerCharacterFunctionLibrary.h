#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerCharacterFunctionLibrary.generated.h"

class AActor;
class AFSDPlayerState;
class APlayerCharacter;
class UObject;
UCLASS(Blueprintable)
class UPlayerCharacterFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPlayerCharacterFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SetPlayerVoiceMuted(UObject* WorldContextObject, AFSDPlayerState* PlayerState, bool Mute, bool TrySystemWide, int32 LocalUserNum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPlayerVoiceMuted(UObject* WorldContextObject, AFSDPlayerState* PlayerState, int32 LocalUserNum);
    static APlayerCharacter* GetRandomPlayer(UObject* WorldContextObject, bool MustBeAlive, bool MustNotBeParalyzed, const bool IgnoreIncapacitated);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APlayerCharacter* GetNearestVisiblePlayer(AActor* From, float MaxDistance, bool MustBeAlive, bool MustNotBeParalyzed, const bool IgnoreIncapacitated);
    static APlayerCharacter* GetNearestPlayerToPosition(UObject* WorldContextObject, FVector position, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static APlayerCharacter* GetNearestPlayerFrom(UObject* WorldContext, FVector From, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly);
    static APlayerCharacter* GetNearestPlayer(AActor* From, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly);
};
