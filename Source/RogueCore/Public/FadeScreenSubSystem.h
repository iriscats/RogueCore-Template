#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FadeData.h"
#include "FadingDoneDelegate.h"
#include "FadeScreenSubSystem.generated.h"

class UObject;
class UTexture;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UFadeScreenSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFadingDone OnFadeInComplete;
    
    FFadingDone OnFadeOutComplete;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFadeData Fading;
    UFadeScreenSubSystem();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsScreenFadingToBlack(UObject* WorldContext);
    static bool IsScreenFadingFromBlack(UObject* WorldContext);
    static bool IsScreenFading(UObject* WorldContext);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentFadeAmount() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void FadeScreenToBlack(UObject* WorldContext, float FadeTime, float Delay, bool ResetExistingFades, bool CapFramerate, bool FadeWorldOnly, bool ToSpaceRig, UTexture* LoadingImage);
    static void FadeScreenFromBlack(UObject* WorldContext, float FadeTime, float Delay, bool ResetExistingFades, bool CapFramerate, bool FadeWorldOnly, bool ToSpaceRig);
    static void BlackoutScreen(UObject* WorldContext, bool FadeWorldOnly);
};
