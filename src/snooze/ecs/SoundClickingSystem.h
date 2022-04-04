#pragma once

#include <forge/engine/audio/AudioAgent.h>
#include <forge/engine/ecs/System.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/SoundClickableComponent.h>

//----------------------------------------------------------------------------
class SoundClickingSystem : public forge::System<SoundClickableComponent>
                          , public forge::AudioAgent
{
public:
    void OnStart() override;
    void OnStop() override;

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    struct ClickEventData
    {
        bool Pressed;
        forge::Entity::CPtr ClickedEntity;
    };

    forge::Vector<ClickEventData> m_ClickEvents;

};
