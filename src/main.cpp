#include <snooze/Precomp.h>
#include <snooze/Snooze.h>

int main(void)
{
    Snooze game;
    forge::ForgeGameParam param;

    param.GameName = "snooze";
    param.Camera = forge::CameraType::Elevation;
    param.Resolution = {600, 600};

    game.Init(param);
    game.MainLoop();
    game.Quit();
}
