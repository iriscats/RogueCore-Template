#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EItemSkinType.h"
#include "SkinnableComponent.generated.h"

class AFSDPlayerState;
class UItemID;
class UItemSkin;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USkinnableComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    UItemSkin* EquippedSkinColor;

    

    UItemSkin* EquippedSkinMesh;

    USkinnableComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void UpdateSkin(AFSDPlayerState* Player);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemSkin* EquippedSkinColor;
    
    UItemSkin* EquippedSkinMesh;
    USkinnableComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateSkin(AFSDPlayerState* Player);
    void OnLoadoutChanged();
    static TArray<UItemSkin*> GetSkinsForItem(UItemID* ItemID, EItemSkinType skinType);
    static UItemSkin* GetEquippedSkinMesh(UItemID* ItemID, AFSDPlayerState* Player);
    static UItemSkin* GetEquippedSkinColor(UItemID* ItemID, AFSDPlayerState* Player);
    static UItemSkin* GetEquippedSkin(UItemID* ItemID, EItemSkinType skinType, AFSDPlayerState* Player);
    static TArray<UItemSkin*> GetEquippableColorSkins(UItemID* ItemID, AFSDPlayerState* Player);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemSkin* GetDefaultItemSkin(UItemID* ItemID, EItemSkinType itemSkinType);
    static UItemSkin* GetBaseColorSkinForMeshSkin(UItemID* ItemID, UItemSkin* meshSkin);
    static void EquipSkin(UItemSkin* Skin, UItemID* ItemID, AFSDPlayerState* Player);
};
