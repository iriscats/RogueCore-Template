#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IconGeneratable.h"
#include "Skinnable.h"
#include "Templates/SubclassOf.h"
#include "ItemPreviewActor.generated.h"

class UIconGenerationCameraKey;
class UItemSkin;
class USkinEffect;
UCLASS(Blueprintable, NoExport)
class AItemPreviewActor : public AActor, public ISkinnable, public IIconGeneratable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemSkin* CurrentSkinColor;
    
    UItemSkin* CurrentSkinMesh;
    TSubclassOf<AActor> itemClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UIconGenerationCameraKey* CameraKey_Normal;
    UIconGenerationCameraKey* CameraKey_CloseUp;
    AItemPreviewActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SkinItem(USkinEffect* Skin);
    void SetItemClass(TSubclassOf<AActor> NewItemClass);
    void OnSkinPreviewChanged(UItemSkin* PreviewSkin);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSkinItem(USkinEffect* Skin);
    void OnSkinChanged();
    void ChangeSkin(UItemSkin* skinMesh, UItemSkin* skinColor, bool isPreview);
    // Fix for true pure virtual functions not being implemented
};
