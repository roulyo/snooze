#include <snooze/Story.h>
#include <random>

#include <iostream>

//----------------------------------------------------------------------------
void Story::InitInstance()
{
    m_StoryAdvancement = 0;
}

//----------------------------------------------------------------------------
forge::Vector<forge::String> Story::GetNextStory()
{
    static forge::Vector<forge::Vector<forge::String>> next_storylines;

    // TODO: Integrate Mog's 1.5 improved storyline
    next_storylines.push_back({"I don't want to do it, dammit!"});
    next_storylines.push_back({"We never win a single thing anyway."});
    next_storylines.push_back({"We'll make a shitty shooter", "like every year..."});
    next_storylines.push_back({"And like every year, the theme will suck."});
    next_storylines.push_back({"We'll play the same fucking",  "playlist from ten years ago..."});
    next_storylines.push_back({"... eating low-cost pizzas and tasteless beers ..."});
    next_storylines.push_back({"... IN A FUCKING BASEMENT", "WITH NO FUCKING LIGHTS"});
    next_storylines.push_back({"Why do we inflict this to ourselves?", "What went wrong?"});
    next_storylines.push_back({"Why can't we simply spend a weekend outside", "like NORMAL FUCKING PEOPLE"});
    next_storylines.push_back({"NooOoOoo, we HAVE to willingly deteriorate", "our health!"});
    // TODO: Add moar lines
    next_storylines.push_back({"Which edition is it this time?", "48, 49?"});
    next_storylines.push_back({"50th? Really?"});
    next_storylines.push_back({"And it's the 20th anniversary?"});
    next_storylines.push_back({"Well, better get started then."});

    if (m_StoryAdvancement < next_storylines.size())
    {
        return next_storylines[m_StoryAdvancement++];
    }
    // Story is finished, GTFO
    else
    {
        return forge::Vector<forge::String> ();
    }
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
