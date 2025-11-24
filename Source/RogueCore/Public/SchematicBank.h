#pragma once
#include "CoreMinimal.h"
#include "SchematicBankBase.h"
#include "SchematicBank.generated.h"

class USchematic;
UCLASS(Blueprintable)
class ROGUECORE_API USchematicBank : public USchematicBankBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TSet<USchematic*> Schematics;

    

    USchematicBank();

    UFUNCTION(BlueprintCallable)

    void AddSchematic(USchematic* Schematic);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<USchematic*> Schematics;
    
    USchematicBank();
    UFUNCTION(BlueprintCallable)
    void AddSchematic(USchematic* Schematic);
};
