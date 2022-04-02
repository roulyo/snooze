#pragma once

#include <forge/engine/input/InputMappingScheme.h>
#include <forge/engine/input/InputBinder.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

//----------------------------------------------------------------------------
using LeftClickBinder = forge::MouseButtonBinder<forge::builtin::MouseClickEvent::Ctor<true, forge::Mouse::Button::Left>,
                                                 forge::builtin::MouseClickEvent::Ctor<false, forge::Mouse::Button::Left>>;

using CameraZoomBinder = forge::MouseScrollBinder<forge::builtin::MouseWheelEvent>;
using MouseMovementBinder = forge::MouseMoveBinder<forge::builtin::MouseMoveEvent> ;

//----------------------------------------------------------------------------
class BaseInputMapping : public forge::InputMappingScheme
{
public:
    BaseInputMapping();

private:
    LeftClickBinder     m_LeftClickBinder;
    MouseMovementBinder m_MouseMoveBinder;
    CameraZoomBinder    m_CameraZoomBinder;

};

