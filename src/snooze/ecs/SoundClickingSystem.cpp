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
            if (it->Pressed)
            {
                const auto& sound = _entity->GetComponent<SoundClickableComponent>().GetOnPressSound();

                if (sound != nullptr)
                {
                    PlaySound(sound);
                }
            }
            else
            {
                const auto& sound = _entity->GetComponent<SoundClickableComponent>().GetOnReleaseSound();

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
