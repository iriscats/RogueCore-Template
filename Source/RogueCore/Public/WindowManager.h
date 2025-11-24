#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/UnrealType.h"
#include "Templates/SubclassOf.h"
#include "WindowManagerDelegateDelegate.h"
#include "WindowManager.generated.h"

class APawn;
class USoundBase;
class UUserWidget;
class UWindowWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UWindowManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindowManagerDelegate OnFirstWindowOpened;
    
    FWindowManagerDelegate OnLastWindowClosed;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* AudioWindowOpen;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWindowWidget*> WindowStack;
    TMap<TSubclassOf<UWindowWidget>, UWindowWidget*> WindowList;
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UUserWidget>, TWeakObjectPtr<UUserWidget>> WidgetSingletonCache;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ResolutionDownscaleActive;
    UWindowManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetSingletonWidgetVisibility(TSubclassOf<UUserWidget> WidgetClass, ESlateVisibility Visibility);
    void ResetHUD();
    void ReplaceWindow(UWindowWidget* Window);
    UWindowWidget* OpenWindowFromSoftClass(TSoftClassPtr<UWindowWidget> WindowClass, int32 ZOrder, bool ShowCursor);
    UWindowWidget* OpenWindowFromClass(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder, bool ShowCursor);
    void OpenWindow(UWindowWidget* Window, bool PlayAudio, bool ShowCursor);
    UWindowWidget* OpenSingleUseWindow(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder);
    void OnPossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWindowOpen(UWindowWidget* Window) const;
    bool IsTopWindow(UWindowWidget* Window) const;
    UUserWidget* GetOrCreateSingletonWidget(TSubclassOf<UUserWidget> WidgetClass, bool& WidgetCreated);
    UWindowWidget* GetCurrentWindow() const;
    UWindowWidget* CreateWindowFromSoftClass(TSoftClassPtr<UWindowWidget> WindowClass, int32 ZOrder);
    UWindowWidget* CreateWindowFromClass(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder);
    void CloseWindow(UWindowWidget* Window);
    void CloseTopWindow();
    void CloseAllWindows();
    void CenterCursor();
    bool AnyWindowsOpen() const;
};
