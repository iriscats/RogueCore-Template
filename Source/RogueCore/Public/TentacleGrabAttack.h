#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackBaseComponent.h"
#include "TentacleGrabAttack.generated.h"

class UMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTentacleGrabAttack : public UAttackBaseComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* HeadMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TerrainCheckSocket;
    FVector TerrainCheckBox;
    UTentacleGrabAttack(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHeadNearTerrain() const;
};
