#include "RunHistoryNetMessage.h"

FRunHistoryNetMessage::FRunHistoryNetMessage() {
    this->Sender = NULL;
    this->TargetState = NULL;
    this->DataSent = 0;
    this->Type = ERunHistoryNetMessageDataType::DamageData;
}

