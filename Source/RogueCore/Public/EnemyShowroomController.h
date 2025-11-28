#pragma once
#include "CoreMinimal.h"
#include "ShowroomController.h"
#include "EnemyShowroomController.generated.h"

class AEnemyShowroomItem;
class UAnimSequenceBase;
class UEnemyShowroomController;
class UObject;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyShowroomController : public UShowroomController {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEnemyShowroomItem* EnemyInstance;
    
    UEnemyShowroomController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_PlayAttack(UAnimSequenceBase* attackAnimation);
    UFUNCTION(BlueprintCallable)
    void PlayAttack(UAnimSequenceBase* Animation);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UEnemyShowroomController* DisplayEnemy(UObject* WorldContextObject, TSoftClassPtr<AEnemyShowroomItem> EnemyPreviewActor);
};
