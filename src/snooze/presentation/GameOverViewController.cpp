#include <snooze/Precomp.h>
#include <snooze/presentation/GameOverViewController.h>

#include <forge/builtin/presentation/behaviors/ClickableBehavior.h>
#include <forge/builtin/presentation/behaviors/HoverableBehavior.h>

#include <snooze/GameEvents.h>
#include <snooze/Snooze.h>

//----------------------------------------------------------------------------
GameOverViewController::GameOverViewController()
{
}

//----------------------------------------------------------------------------
void GameOverViewController::OnStart()
{
    bool isSuccess = Snooze::IsGameCompleted();

    m_GameOverView = new GameOverView(isSuccess);

    if (isSuccess)
    {
        m_GameOverView->GetButton().AddBehavior<forge::builtin::ClickableBehavior>(
            FRG__BIND_BEHAVIOR(GameOverViewController, OnQuitClicked, this)
        );
    }
    else
    {
        m_GameOverView->GetButton().AddBehavior<forge::builtin::ClickableBehavior>(
            FRG__BIND_BEHAVIOR(GameOverViewController, OnRetryClicked, this)
        );
    }

    m_GameOverView->GetButton().AddBehavior<forge::builtin::HoverableBehavior>(
        FRG__BIND_BEHAVIOR(GameOverViewController, OnButtonHovered, this)
    );

    OpenView(m_GameOverView);
}

//----------------------------------------------------------------------------
void GameOverViewController::OnStop()
{
    CloseView(m_GameOverView);
    delete m_GameOverView;
}

//----------------------------------------------------------------------------
void GameOverViewController::Update()
{
}

//----------------------------------------------------------------------------
void GameOverViewController::OnRetryClicked(forge::GUIWidget* _widget,
                                            const forge::SystemEvent& _event)
{
    RetryRequestedEvent::Broadcast();
}

//----------------------------------------------------------------------------
void GameOverViewController::OnQuitClicked(forge::GUIWidget* _widget,
                                           const forge::SystemEvent& _event)
{
    QuitRequestedEvent::Broadcast();
}

//----------------------------------------------------------------------------
void GameOverViewController::OnButtonHovered(forge::GUIWidget* _widget,
                                             const forge::SystemEvent& _event)
{
    forge::builtin::gui::QuadTextPanel* widget =
        static_cast<forge::builtin::gui::QuadTextPanel*>(_widget);

    if (_event.Type ==  forge::SystemEvent::MouseEntered)
    {
        widget->GetText()->SetFillColor({ 255, 255, 255 });
    }
    else
    {
        widget->GetText()->SetFillColor({ 200, 200, 200 });
    }
}
