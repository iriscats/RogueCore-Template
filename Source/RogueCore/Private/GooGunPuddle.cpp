#include "GooGunPuddle.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "SimpleHealthComponent.h"
#include "Templates/SubclassOf.h"

AGooGunPuddle::AGooGunPuddle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void AGooGunPuddle::SetStatusEffect(TSubclassOf<UStatusEffect> NewStatusEffect) {
}


void AGooGunPuddle::OnRep_ActiveStatusEffectTriggersMask(int32 PreviousMask) {
}

void AGooGunPuddle::OnPuddleEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AGooGunPuddle::OnPuddleBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AGooGunPuddle::OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent) {
}


void AGooGunPuddle::IgniteGoo_Implementation() {
}

void AGooGunPuddle::AddStatusEffect(TSubclassOf<UStatusEffect> NewStatusEffect) {
}

void AGooGunPuddle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGooGunPuddle, ActiveStatusEffectTriggersMask);
    DOREPLIFETIME(AGooGunPuddle, Lifetime);
}


