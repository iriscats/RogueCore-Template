#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EArmorMeshType.h"
#include "Templates/SubclassOf.h"
#include "VanityCharacter.generated.h"

class AItem;
class UAnimSequenceBase;
class UArmorMaterialVanityItem;
class UArmorVanityItem;
class UBeardColorVanityItem;
class UBeardVanityItem;
class UChildActorComponent;
class UEyeBrowsVanityItem;
class UHeadVanityItem;
class UItemSkin;
class UMaterialInterface;
class UMoustacheVanityItem;
class USideburnsVanityItem;
class USkeletalMeshComponent;
class USkinColorVanityItem;
UCLASS(Blueprintable)
class AVanityCharacter : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* ChildActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* Animation;
    USkinColorVanityItem* skinColor;
    UBeardColorVanityItem* BeardColor;
    UBeardColorVanityItem* DynamicBeardColor;
    UHeadVanityItem* Head;
    UEyeBrowsVanityItem* EyeBrows;
    USideburnsVanityItem* Sideburns;
    UMoustacheVanityItem* Moustache;
    UBeardVanityItem* Beard;
    UArmorVanityItem* Armor;
    EArmorMeshType ArmorMeshType;
    UArmorMaterialVanityItem* ArmorColor;
    UArmorMaterialVanityItem* UndersuitColor;
    USkeletalMeshComponent* mesh;
    USkeletalMeshComponent* BodyMesh;
    UBeardColorVanityItem* DefaultHairColor;
    UMaterialInterface* DefaultArmorMaterial;
    UMaterialInterface* DefaultUndersuitMaterial;
    TSubclassOf<AItem> itemClass;
    UItemSkin* Framework;
    UItemSkin* Paintjob;
    AVanityCharacter(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void DisplayVanity();
    void Clean();
};
