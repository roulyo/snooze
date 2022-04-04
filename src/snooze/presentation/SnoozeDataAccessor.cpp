#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeDataAccessor.h>

//----------------------------------------------------------------------------
u32 SnoozeDataAccessor::GetRemainingTimeMs() const
{
    if (GetColumn<SnoozableComponent>().size() > 0)
    {
        return GetColumn<SnoozableComponent>()[0]
            ->GetComponent<SnoozableComponent>()
            .GetTimer().GetRemainingTimeMs();
    }

    return 0;
}
