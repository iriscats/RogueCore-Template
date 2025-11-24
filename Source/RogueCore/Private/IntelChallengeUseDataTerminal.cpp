#include "IntelChallengeUseDataTerminal.h"

UIntelChallengeUseDataTerminal::UIntelChallengeUseDataTerminal() {
    this->RequiredUseAmount = 1;
    this->RequiredRunDepth = ERunDepth::None;
    this->RequireMutator = false;
}

void UIntelChallengeUseDataTerminal::OnActivatedTerminal(AActor* TerminalActor) {
}


