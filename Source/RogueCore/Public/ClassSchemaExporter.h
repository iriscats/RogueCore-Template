#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ClassSchemaExporter.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UClassSchemaExporter : public UObject {
    GENERATED_BODY()
public:
    UClassSchemaExporter();
    UFUNCTION(BlueprintCallable)
    static void PrintClassSchemaToLog(const UClass* TargetClass);
    
};
