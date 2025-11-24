#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_FSDTimedNiagaraEffect.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_FSDTimedNiagaraEffect : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* Template;
    
    FName SocketName;
    FVector LocationOffset;
    FRotator RotationOffset;
    bool IsFirstPerson;
    bool bDestroyAtEnd;
    UAnimNotifyState_FSDTimedNiagaraEffect();
};
