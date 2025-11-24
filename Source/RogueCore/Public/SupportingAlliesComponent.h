#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SupportingAlliesComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USupportingAlliesComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> SupportiveActors;
    
    USupportingAlliesComponent(const FObjectInitializer& ObjectInitializer);
};
