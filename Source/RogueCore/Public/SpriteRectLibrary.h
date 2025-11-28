#pragma once
#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpriteRect.h"
#include "SpriteRectLibrary.generated.h"

UCLASS(Blueprintable)
class USpriteRectLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USpriteRectLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSpriteRect TranslateSpriteRect(FSpriteRect Rect, FVector2D Offset);
    
    static bool SpriteRectIntersectsAny(FSpriteRect A, TArray<FSpriteRect> Others);
    static bool SpriteRectIntersects(FSpriteRect A, FSpriteRect B);
    UFUNCTION(BlueprintCallable)
    static void MoveSpriteRect(UPARAM(Ref) FSpriteRect& Rect, FVector2D Offset);
    static FSpriteRect MakeSpriteRectFromPoints(FVector2D Start, FVector2D End);
    static FSpriteRect MakeSpriteRectFromCenter(FVector2D Center, FVector2D Size);
    static void MakeGateSpriteRects(int32 CanvasHeight, int32 GateWidth, FVector OpeningPos, float OpeningHeight, FSpriteRect& OutTopRect, FSpriteRect& OutBottomRect);
    static FVector2D GetSpriteRectSize(FSpriteRect Rect);
    static FVector2D GetSpriteRectCenter(FSpriteRect Rect);
};
