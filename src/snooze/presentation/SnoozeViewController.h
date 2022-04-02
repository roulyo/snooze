#pragma once

#include <forge/engine/presentation/ViewController.h>

#include <snooze/presentation/SnoozeDataAccessor.h>
#include <snooze/presentation/SnoozeView.h>

//----------------------------------------------------------------------------
class SnoozeViewController : public forge::AbstractViewController
{
public:
    SnoozeViewController();

    void OnStart() override;
    void OnStop() override;

    void Update() override;

private:
    SnoozeView*         m_View;
    SnoozeDataAccessor  m_SDA;

};
