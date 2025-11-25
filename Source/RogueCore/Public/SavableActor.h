#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "SavableActor.generated.h"

UCLASS(Blueprintable, NoExport)
class ASavableActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    ASavableActor(const FObjectInitializer& ObjectInitializer);
};
