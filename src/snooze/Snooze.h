#include <forge/engine/game/Game.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class Snooze : public forge::AbstractForgeGame
{
public:
    Snooze();
    ~Snooze() override;

    void OnInit() override;
    void OnQuit() override;

private:
    void OnStartMiniGameRequestEvent(const StartMiniGameRequestEvent& _event);
    void OnStopMiniGameRequestEvent(const StopMiniGameRequestEvent& _event);

private:
    forge::Vector<ComponentId>  m_MiniGames;
    ComponentId                 m_CurrentGame;

};
