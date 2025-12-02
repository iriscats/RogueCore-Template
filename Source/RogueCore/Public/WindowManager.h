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
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindowManagerDelegate OnFirstWindowOpened;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindowManagerDelegate OnLastWindowClosed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* AudioWindowOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWindowWidget*> WindowStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UWindowWidget>, UWindowWidget*> WindowList;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UUserWidget>, TWeakObjectPtr<UUserWidget>> WidgetSingletonCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ResolutionDownscaleActive;
    
public:
    UWindowManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSingletonWidgetVisibility(TSubclassOf<UUserWidget> WidgetClass, ESlateVisibility Visibility);
    
    UFUNCTION(BlueprintCallable)
    void ResetHUD();
    
    UFUNCTION(BlueprintCallable)
    void ReplaceWindow(UWindowWidget* Window);
    
    UFUNCTION(BlueprintCallable)
    UWindowWidget* OpenWindowFromSoftClass(TSoftClassPtr<UWindowWidget> WindowClass, int32 ZOrder, bool ShowCursor);
    
    UFUNCTION(BlueprintCallable)
    UWindowWidget* OpenWindowFromClass(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder, bool ShowCursor);
    
    UFUNCTION(BlueprintCallable)
    void OpenWindow(UWindowWidget* Window, bool PlayAudio, bool ShowCursor);
    
    UFUNCTION(BlueprintCallable)
    UWindowWidget* OpenSingleUseWindow(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder);

    UFUNCTION(BlueprintCallable)
    void OnPossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWindowOpen(UWindowWidget* Window) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTopWindow(UWindowWidget* Window) const;
    
    UFUNCTION(BlueprintCallable)
    UUserWidget* GetOrCreateSingletonWidget(TSubclassOf<UUserWidget> WidgetClass, bool& WidgetCreated);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWindowWidget* GetCurrentWindow() const;
    
    UFUNCTION(BlueprintCallable)
    UWindowWidget* CreateWindowFromSoftClass(TSoftClassPtr<UWindowWidget> WindowClass, int32 ZOrder);
    
    UFUNCTION(BlueprintCallable)
    UWindowWidget* CreateWindowFromClass(TSubclassOf<UWindowWidget> WindowClass, int32 ZOrder);
    
    UFUNCTION(BlueprintCallable)
    void CloseWindow(UWindowWidget* Window);
    
    UFUNCTION(BlueprintCallable)
    void CloseTopWindow();
    
    UFUNCTION(BlueprintCallable)
    void CloseAllWindows();
    
protected:
    UFUNCTION(BlueprintCallable)
    void CenterCursor();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyWindowsOpen() const;
    
};
