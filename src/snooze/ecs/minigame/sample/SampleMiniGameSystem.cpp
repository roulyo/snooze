#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameSystem.h>

#include <iostream>

//----------------------------------------------------------------------------
void SampleMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    SampleMiniGameComponent& comp = _entity->GetComponent<SampleMiniGameComponent>();

    BaseMiniGame::Update(comp);

    //std::cout << "SampleMiniGameSystem updates" << std::endl;

    if (m_Chrono.IsElapsed())
    {
        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStart()
{
    std::cout << "SampleMiniGameSystem starts" << std::endl;

    m_Chrono.Start(5000);
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStop()
{
    std::cout << "SampleMiniGameSystem stops" << std::endl;
}
