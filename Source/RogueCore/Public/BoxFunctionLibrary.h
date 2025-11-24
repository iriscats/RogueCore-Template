#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BoxFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UBoxFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBoxFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBox CreateBoxAt(FVector Location, FVector Size);
    
    UFUNCTION(BlueprintCallable)
    static FVector ClosestPointToBox(FVector Pos, const FBox& Box);
    static float BoxSize(FBox Box);
    static FVector BoxExtends(FBox Box);
    static FVector BoxCenter(FBox Box);
};
