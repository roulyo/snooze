#include <snooze/Precomp.h>
#include <snooze/presentation/GameOverView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/FontCatalog.h>

//----------------------------------------------------------------------------
GameOverView::GameOverView(bool _success)
{
    SetupBackground();
    SetupGameOverText(_success);
    SetupMiscText(_success);
    SetupButton(_success);

    AddWidget(&m_Background);
    AddWidget(&m_GameOverText);
    AddWidget(&m_MiscText);
    AddWidget(&m_Button);
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& GameOverView::GetButton()
{
    return m_Button;
}

//----------------------------------------------------------------------------
void GameOverView::SetupBackground()
{
    m_Background.GetBackground()->SetFillColor({ 51, 51, 51 });
}

//----------------------------------------------------------------------------
void GameOverView::SetupGameOverText(bool _success)
{
    m_GameOverText.SetRelativeSize({ 100.f, 100.f / 3.f });

    m_GameOverText.GetBackground()->SetFillColor({ 0, 0, 0, 0 });

    m_GameOverText.GetText()->SetFont(forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::AlarmClock));
    m_GameOverText.GetText()->SetSize(128);

    if (_success)
    {
        m_GameOverText.GetText()->SetString("Thanks for playing");
        m_GameOverText.GetText()->SetFillColor({ 0, 255, 0 });
    }
    else
    {
        m_GameOverText.GetText()->SetString("Game Over");
        m_GameOverText.GetText()->SetFillColor({ 255, 0, 0 });
    }
}

//----------------------------------------------------------------------------
void GameOverView::SetupMiscText(bool _success)
{
    m_MiscText.SetRelativeSize({ 100.f, 100.f / 3.f });
    m_MiscText.SetRelativePadding({ 0.f, 100.f / 3.f });

    m_MiscText.GetBackground()->SetFillColor({ 0, 0, 0, 0 });

    m_MiscText.GetText()->SetFont(forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::StoryFont));
    m_MiscText.GetText()->SetSize(78);

    if (_success)
    {
        m_MiscText.GetText()->SetString("Mogmi - Roulyo - Sp1d3b0y");
        m_MiscText.GetText()->SetFillColor({ 0, 200, 0 });
    }
    else
    {
        m_MiscText.GetText()->SetString("Time's out...");
        m_MiscText.GetText()->SetFillColor({ 200, 0, 0 });
    }
}

//----------------------------------------------------------------------------
void GameOverView::SetupButton(bool _success)
{
    m_Button.SetRelativeSize({ 33.f, 100.f / 3.f });
    m_Button.SetRelativePadding({ 33.f, 200.f / 3.f });

    m_Button.GetBackground()->SetFillColor({ 0, 0, 0, 0 });

    m_Button.GetText()->SetFont(forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::StoryFont));
    m_Button.GetText()->SetFillColor({ 200, 200, 200 });
    m_Button.GetText()->SetSize(96);

    if (_success)
    {
        m_Button.GetText()->SetString("See you again");
    }
    else
    {
        m_Button.GetText()->SetString("Retry");
    }
}
