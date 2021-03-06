#include <snooze/Precomp.h>
#include <snooze/ecs/SoundClickingSystem.h>

//----------------------------------------------------------------------------
void SoundClickingSystem::OnStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &SoundClickingSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SoundClickingSystem::OnStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &SoundClickingSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SoundClickingSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    auto it = m_ClickEvents.begin();

    while (it != m_ClickEvents.end())
    {
        if (it->ClickedEntity == _entity)
        {
            const SoundClickableComponent& soundClickComp =
                _entity->GetComponent<SoundClickableComponent>();

            if (!soundClickComp.GetIsMute())
            {
                const forge::Sound::Ptr& sound = it->Pressed ? soundClickComp.GetOnPressSound()
                                                             : soundClickComp.GetOnReleaseSound();

                if (sound != nullptr)
                {
                    PlaySound(sound);
                }
            }

            it = m_ClickEvents.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

//----------------------------------------------------------------------------
void SoundClickingSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    ClickEventData clickEvent;
    clickEvent.Pressed = _event.GetIsPressed();
    clickEvent.ClickedEntity = _event.GetEntity();

    m_ClickEvents.push_back(clickEvent);
}
