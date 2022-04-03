#pragma once

#include <forge/engine/presentation/ViewController.h>
#include <forge/engine/time/Chrono.h>

#include <snooze/presentation/SnoozeDataAccessor.h>
#include <snooze/presentation/SnoozeView.h>
#include <snooze/presentation/StoryView.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class SnoozeViewController : public forge::AbstractViewController
{
public:
    SnoozeViewController();

    void OnStart() override;
    void OnStop() override;

    void Update() override;

private:
    void OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event);

private:
    SnoozeView*         m_SnoozeView;
    StoryView*          m_StoryView;

    forge::Chrono       m_StoryTimer;

    SnoozeDataAccessor  m_SDA;

};
