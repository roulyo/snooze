#pragma once

#include <forge/engine/audio/AudioAgent.h>
#include <forge/engine/presentation/ViewController.h>
#include <forge/engine/time/Chrono.h>

#include <snooze/presentation/ConfigView.h>
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
    void UpdateSnoozeView();
    void UpdateStoryView();
    void UpdateThoughtView();

    void DisplayNextAvailableStoryPage();
    void UpdateCurrentStoryDisplay();

    void DisplayThought();

    void OnButtonPushedEvent(const ButtonPushedEvent& _event);
    void OnItemAcquieredEvent(const ItemAcquieredEvent& _event);
    void OnItemLostEvent(const ItemLostEvent& _event);

    void OnMuteSoundClicked(forge::GUIWidget* _widget,
                            const forge::SystemEvent& _event);
    void OnMuteMusicClicked(forge::GUIWidget* _widget,
                            const forge::SystemEvent& _event);

private:
    ItemView*                       m_ItemView;
    SnoozeView*                     m_SnoozeView;
    StoryView*                      m_StoryView;
    ThoughtView*                    m_ThoughtView;
    ConfigView*                     m_ConfigView;
        
    forge::Chrono                   m_StoryTimer;
    forge::Vector<forge::String>    m_StoryPages;
    struct
    {
        forge::String               Content;
        u32                         Index;
    }                               m_CurrentStory;

    forge::Chrono                   m_ThoughtTimer;
    forge::String                   m_Thought;

    bool                            m_SoundMuted;
    bool                            m_MusicMuted;

    SnoozeDataAccessor              m_SDA;

};
