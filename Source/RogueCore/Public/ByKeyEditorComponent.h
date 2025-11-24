#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ByKeyEditorComponent.generated.h"

class UEnemyDescriptor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UByKeyEditorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* Enemy;
    
    UByKeyEditorComponent(const FObjectInitializer& ObjectInitializer);
};
