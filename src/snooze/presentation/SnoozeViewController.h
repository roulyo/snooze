#pragma once

#include <forge/engine/audio/AudioAgent.h>
#include <forge/engine/presentation/ViewController.h>
#include <forge/engine/time/Chrono.h>

#include <snooze/presentation/ItemView.h>
#include <snooze/presentation/SnoozeDataAccessor.h>
#include <snooze/presentation/SnoozeView.h>
#include <snooze/presentation/StoryView.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class SnoozeViewController : public forge::AbstractViewController
                           , public forge::AudioAgent
{
public:
    SnoozeViewController();

    void OnStart() override;
    void OnStop() override;

    void Update() override;

private:
    void OnButtonPushedEvent(const ButtonPushedEvent& _event);
    void OnItemAcquieredEvent(const ItemAcquieredEvent& _event);
    void OnItemLostEvent(const ItemLostEvent& _event);

    void DisplayNextAvailableStoryPage();
    void UpdateCurrentStoryDisplay();

private:
    ItemView*                       m_ItemView;
    SnoozeView*                     m_SnoozeView;
    StoryView*                      m_StoryView;

    forge::Chrono                   m_StoryTimer;
    forge::Vector<forge::String>    m_StoryPages;
    struct
    {
        forge::String               Content;
        u32                         Index;
    }                               m_CurrentStory;

    SnoozeDataAccessor              m_SDA;

};
