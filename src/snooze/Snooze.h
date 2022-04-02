#include <forge/engine/game/Game.h>

//----------------------------------------------------------------------------
class Snooze : public forge::AbstractForgeGame
{
public:
    Snooze();
    ~Snooze() override;
    
    void OnInit() override;
    void OnQuit() override;

};

