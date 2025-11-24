#pragma once
#include "CoreMinimal.h"
#include "MULE.h"
#include "MiniMule.generated.h"

class AGem;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API AMiniMule : public AMULE {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TArray<AGem*> LostLegs;

    

    AMiniMule(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AGem*> LostLegs;
    
    AMiniMule(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetLegsVisibleOnScanner();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnLegsSetVisible();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AGem*> FindLegsInLevelSortedByDistance() const;
    void CheatRepair();
};
