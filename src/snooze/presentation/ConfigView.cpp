#include <snooze/Precomp.h>
#include <snooze/presentation/ConfigView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/SpriteCatalog.h>

//----------------------------------------------------------------------------
ConfigView::ConfigView()
{
    m_MuteSoundButton.SetGravity(forge::GUIGravity::Left);
    m_MuteSoundButton.SetRelativeSize({ 50, 100 });
    m_MuteSoundButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::SoundOn));
    m_MuteMusicButton.SetGravity(forge::GUIGravity::Right);
    m_MuteMusicButton.SetRelativeSize({ 50, 100 });
    m_MuteMusicButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MusicOn));

    AddWidget(&m_MuteSoundButton);
    AddWidget(&m_MuteMusicButton);
}

//----------------------------------------------------------------------------
void ConfigView::SetSoundOn()
{
    m_MuteSoundButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::SoundOn));
}

//----------------------------------------------------------------------------
void ConfigView::SetSoundOff()
{
    m_MuteSoundButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::SoundOff));
}

//----------------------------------------------------------------------------
void ConfigView::SetMusicOn()
{
    m_MuteMusicButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MusicOn));
}

//----------------------------------------------------------------------------
void ConfigView::SetMusicOff()
{
    m_MuteMusicButton.GetBackground()->SetSprite(
        forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MusicOff));
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadPanel& ConfigView::GetMuteSoundButton()
{
    return m_MuteSoundButton;
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadPanel& ConfigView::GetMuteMusicButton()
{
    return m_MuteMusicButton;
}
