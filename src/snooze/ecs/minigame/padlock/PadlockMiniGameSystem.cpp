#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameSystem.h>

#include <iostream>

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    PadlockMiniGameComponent& comp = _entity->GetComponent<PadlockMiniGameComponent>();

    BaseMiniGame::Update(comp);

    if (m_Chrono.IsElapsed())
    {
        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStart()
{
    std::cout << "PadlockMiniGameSystem starts" << std::endl;

    m_Chrono.Start(5000);
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStop()
{
    std::cout << "PadlockMiniGameSystem stops" << std::endl;
}
