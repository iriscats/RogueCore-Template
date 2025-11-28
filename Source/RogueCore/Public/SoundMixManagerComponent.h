#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoundMixManagerItem.h"
#include "SoundMixManagerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USoundMixManagerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSoundMixManagerItem> SoundMixes;
    
    USoundMixManagerComponent(const FObjectInitializer& ObjectInitializer);
};
