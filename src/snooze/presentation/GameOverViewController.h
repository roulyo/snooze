#pragma once

#include <forge/engine/presentation/ViewController.h>

#include <snooze/presentation/SnoozeDataAccessor.h>
#include <snooze/presentation/SnoozeView.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class GameOverViewController : public forge::AbstractViewController
{
public:
    GameOverViewController();

    void OnStart() override;
    void OnStop() override;

    void Update() override;
};
