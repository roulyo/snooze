#include <snooze/Precomp.h>
#include <snooze/gamestate/BaseInputMapping.h>

#include <forge/engine/input/InputTypes.h>

//----------------------------------------------------------------------------
BaseInputMapping::BaseInputMapping()
{
    RegisterInputBinder(forge::Mouse::Button::Left, &m_LeftClickBinder);
    RegisterInputBinder(forge::Mouse::Move::Move, &m_MouseMoveBinder);
    RegisterInputBinder(forge::Mouse::Wheel::VerticalWheel, &m_CameraZoomBinder);
}
