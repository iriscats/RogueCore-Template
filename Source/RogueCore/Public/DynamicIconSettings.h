#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DynamicIconSettings.generated.h"

class UMaterialInstance;
UCLASS(Blueprintable)
class UDynamicIconSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* TextureDynamicIcon;
    
    UMaterialInstance* TwoFacetDynamicIcon;
    UMaterialInstance* TwoFacetDynamicIconTex1;
    UMaterialInstance* TwoFacetDynamicIconTex2;
    UMaterialInstance* TwoFacetDynamicIconTex1Tex2;
    UMaterialInstance* TriFacetDynamicIcon;
    UMaterialInstance* TriFacetDynamicIconTex1;
    UMaterialInstance* TriFacetDynamicIconTex1Tex2;
    UMaterialInstance* TriFacetDynamicIconTex1Tex3;
    UMaterialInstance* TriFacetDynamicIconTex1Tex2Tex3;
    UMaterialInstance* TriFacetDynamicIconTex2;
    UMaterialInstance* TriFacetDynamicIconTex2Tex3;
    UMaterialInstance* TriFacetDynamicIconTex3;
    UDynamicIconSettings();
};
