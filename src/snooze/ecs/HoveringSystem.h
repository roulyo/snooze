#pragma once

#include <forge/engine/ecs/System.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/HoverableComponent.h>

//----------------------------------------------------------------------------
class HoveringSystem : public forge::System<HoverableComponent>
{
public:
    void OnStart() override;
    void OnStop() override;

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void OnEntityHoveredEnterEvent(const forge::builtin::EntityHoveredEnterEvent& _event);
    void OnEntityHoveredExitEvent(const forge::builtin::EntityHoveredExitEvent& _event);

private:
    struct HoveringEventData
    {
        bool Entered;
        forge::Entity::CPtr HoveredEntity;
    };

    forge::Vector<HoveringEventData> m_HoveringEvents;

};
