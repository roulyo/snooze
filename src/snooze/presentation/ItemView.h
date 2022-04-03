#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/Panel.h>

//----------------------------------------------------------------------------
class ItemView : public forge::View
{
public:
    ItemView();

    forge::builtin::gui::QuadPanel& GetItemPanel();

private:
    forge::builtin::gui::QuadPanel  m_Background;
    forge::builtin::gui::QuadPanel  m_ItemPanel;

};
