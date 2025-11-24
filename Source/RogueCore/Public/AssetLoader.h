#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AssetLoader.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UAssetLoader : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UAssetLoader();
};
