#pragma once
#include "CoreMinimal.h"
#include "BasicUserWidget.h"
#include "BasicRichTextRunner.generated.h"

class UDataTable;
class URichTextRunnerInternal;
UCLASS(Blueprintable, EditInlineNew)
class UBasicRichTextRunner : public UBasicUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UDataTable* TextStyleSet;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Progress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URichTextRunnerInternal* InternalRichText;
    UBasicRichTextRunner();
    UFUNCTION(BlueprintCallable)
    void SetTextStyleSet(UDataTable* NewTextStyleSet);
    void SetText(FText InText);
    void SetProgress(float InProgress);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDataTable* GetTextStyleSet() const;
    float GetProgress() const;
};
