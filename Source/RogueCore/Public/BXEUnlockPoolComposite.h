#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockCollection.h"
#include "BXEUnlockPoolComposite.generated.h"

class UBXEUnlockPool;
UCLASS(Blueprintable)
class UBXEUnlockPoolComposite : public UBXEUnlockCollection {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TSet<UBXEUnlockPool*> UnlockPools;


    UBXEUnlockPoolComposite();

};
