#include "VoteOptionPool.h"

UVoteOptionPool::UVoteOptionPool() {
    this->LockTelemetryIdentifier = false;
}

TArray<UVoteOptionAction*> UVoteOptionPool::GetVoteOptionActions() {
    return TArray<UVoteOptionAction*>();
}


