#pragma once
#include "CoreMinimal.h"
#include "SimpleObjectInfoComponent.h"
#include "EnemyComponent.generated.h"

class UDialogDataAsset;
class UEnemyFamily;
class UEnemyID;
class UTexture2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyComponent : public USimpleObjectInfoComponent {
    GENERATED_BODY()

public:
    UEnemyComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    UEnemyID* GetID() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetFamilyName() const;

    UTexture2D* GetFamilyIcon() const;
};
