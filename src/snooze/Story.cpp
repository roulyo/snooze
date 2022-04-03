#include <snooze/Story.h>
#include <random>

//----------------------------------------------------------------------------
void Story::InitInstance()
{
    m_StoryAdvancement = 0;
}

//----------------------------------------------------------------------------
forge::Vector<forge::String> Story::GetNextStory()
{
    static forge::Vector<forge::Vector<forge::String>> next_storylines;

    next_storylines.push_back({"test1"});
    next_storylines.push_back({"test2"});

    return next_storylines[m_StoryAdvancement++];
}

//----------------------------------------------------------------------------
forge::Vector<forge::String> Story::GetRandomThought()
{
    static std::random_device rd;
    static forge::Vector<forge::Vector<forge::String>> random_thoughts;

    random_thoughts.push_back({"Oh come on, one more minute..."});
    random_thoughts.push_back({"But I'm so comfy here..."});
    random_thoughts.push_back({"Is it time already?"});
    random_thoughts.push_back({"Ok, one last time."});
    random_thoughts.push_back({"Uuuuugh, not again..."});

    return random_thoughts[rd() % random_thoughts.size()];
}
