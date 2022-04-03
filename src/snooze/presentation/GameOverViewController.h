#pragma once

#include <forge/engine/presentation/ViewController.h>

#include <snooze/GameEvents.h>
#include <snooze/presentation/GameOverView.h>

//----------------------------------------------------------------------------
class GameOverViewController : public forge::AbstractViewController
{
public:
    GameOverViewController();

    void OnStart() override;
    void OnStop() override;

    void Update() override;

private:
    void OnRetryClicked(forge::GUIWidget* _widget,
                        const forge::SystemEvent& _event);
    void OnQuitClicked(forge::GUIWidget* _widget,
                       const forge::SystemEvent& _event);
    void OnButtonHovered(forge::GUIWidget* _widget,
                         const forge::SystemEvent& _event);

private:
    GameOverView*   m_GameOverView;

};
