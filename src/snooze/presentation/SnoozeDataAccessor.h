#pragma once

#include <forge/engine/presentation/DataAccessor.h>

#include <snooze/ecs/SnoozableComponent.h>

//----------------------------------------------------------------------------
class SnoozeDataAccessor : public forge::DataAccessor<SnoozableComponent>
{
public:
    u32 GetRemainingTimeMs() const;

};
