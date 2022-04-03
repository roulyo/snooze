#pragma once

#include <forge/engine/ForgeMacros.h>
#include <forge/engine/ForgeTypes.h>

//----------------------------------------------------------------------------
class Story : public forge::Singleton<Story>
{
    FRG__DECL_SINGLETON(Story);

public:
    void InitInstance() override;

    forge::Vector<forge::String> GetNextStory();
    forge::Vector<forge::String> GetRandomThought();

private:
    forge::u32 m_StoryAdvancement;
    forge::Vector<forge::Vector<forge::String>> m_RandomThoughts;
    forge::Vector<forge::Vector<forge::String>> m_Storylines;
};
