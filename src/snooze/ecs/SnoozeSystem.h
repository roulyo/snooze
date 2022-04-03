#pragma once

#include <forge/engine/ecs/System.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>
#include <forge/builtin/rendering/RenderableComponent.h>

#include <snooze/GameEvents.h>
#include <snooze/ecs/SnoozableComponent.h>

//----------------------------------------------------------------------------
class SnoozeSystem : public forge::System<SnoozableComponent,
                                          forge::builtin::RenderableComponent>
{
public:
    void OnStart() override;
    void OnStop() override;

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

    bool IsStandingBy() const override;

private:
    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);
    void OnEntityHoveredEnterEvent(const forge::builtin::EntityHoveredEnterEvent& _event);
    void OnEntityHoveredExitEvent(const forge::builtin::EntityHoveredExitEvent& _event);
    void OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event);

private:
    struct ClickData
    {
        bool IsPressed;
        forge::Entity::CPtr Entity;
    }   m_ClickData;

    bool m_IsStarted;
    bool m_IsPostMiniGame;

};
