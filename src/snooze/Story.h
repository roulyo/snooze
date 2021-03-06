#pragma once

#include <forge/engine/ForgeMacros.h>
#include <forge/engine/ForgeTypes.h>

//----------------------------------------------------------------------------
class Story : public forge::Singleton<Story>
{
    FRG__DECL_SINGLETON(Story);

public:
    void InitInstance() override;

    void Reset();

    const forge::Vector<forge::String>& GetNextStory();
    const forge::String& GetRandomThought();

private:
    forge::u32 m_StoryAdvancement;
    forge::Vector<forge::Vector<forge::String>> m_Storylines;
    forge::Vector<forge::String>                m_RandomThoughts;
};
