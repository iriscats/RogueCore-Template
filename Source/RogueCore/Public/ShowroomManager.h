#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "ShowroomManager.generated.h"

class AShowroomStage;
class UShowroomController;
class UTextureRenderTarget2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UShowroomManager : public UActorComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ShowroomLocation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AShowroomStage> CurrentStage;
    AShowroomStage* StageInstance;
    UTextureRenderTarget2D* RenderTarget;
    UShowroomManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UShowroomController* GetController();
    UFUNCTION(BlueprintCallable)
    void ClearShowroom();
};
