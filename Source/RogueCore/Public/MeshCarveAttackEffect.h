#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackEffect.h"
#include "MeshCarveAttackEffect.generated.h"

class UStaticMesh;
UCLASS(Blueprintable, EditInlineNew)
class UMeshCarveAttackEffect : public UAttackEffect {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpensiveNoise;
    
    UStaticMesh* CarveMesh;
    float CarverOffset;
    FRotator CarverOrientation;
    FVector CarverScale;
    FName Socket;
    UMeshCarveAttackEffect();
};
