#include <snooze/Precomp.h>
#include <snooze/Story.h>
#include <random>

#include <iostream>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
void Story::InitInstance()
{
    m_StoryAdvancement = 0;
    // TODO: Integrate Mog's 1.5 improved storyline
    m_Storylines.push_back({"I don't want to do it, dammit!"});
    m_Storylines.push_back({"We never win a single thing anyway."});
    m_Storylines.push_back({"We'll make a shitty shooter", "like every year..."});
    m_Storylines.push_back({"And like every year, the theme will suck."});
    m_Storylines.push_back({"We'll play the same fucking",  "playlist from ten years ago..."});
    m_Storylines.push_back({"... eating low-cost pizzas and tasteless beers ..."});
    m_Storylines.push_back({"... IN A FUCKING BASEMENT", "WITH NO FUCKING LIGHTS"});
    m_Storylines.push_back({"Why do we inflict this to ourselves?", "What went wrong?"});
    m_Storylines.push_back({"Why can't we simply spend a weekend outside", "like NORMAL FUCKING PEOPLE"});
    m_Storylines.push_back({"NooOoOoo, we HAVE to willingly deteriorate", "our health!"});
    // TODO: Add moar lines
    m_Storylines.push_back({"Which edition is it this time?", "48, 49?"});
    m_Storylines.push_back({"50th? Really?"});
    m_Storylines.push_back({"And it's the 20th anniversary?"});
    m_Storylines.push_back({"Well, better get started then."});

    m_RandomThoughts.push_back({"Oh come on, one more minute..."});
    m_RandomThoughts.push_back({"But I'm so comfy here..."});
    m_RandomThoughts.push_back({"Is it time already?"});
    m_RandomThoughts.push_back({"Ok, one last time."});
    m_RandomThoughts.push_back({"Uuuuugh, not again..."});
}

//----------------------------------------------------------------------------
void Story::Reset()
{
    m_StoryAdvancement = 0;
}

//----------------------------------------------------------------------------
const forge::Vector<forge::String>& Story::GetNextStory()
{
    if (m_StoryAdvancement < m_Storylines.size())
    {
        const forge::Vector<forge::String>& story =
            m_Storylines[m_StoryAdvancement++];

        if (m_StoryAdvancement >= m_Storylines.size())
        {
            StoryCompletedEvent::Broadcast();
        }

        return story;
    }

    FRG__ASSERT(false, "No story left.");

    return m_Storylines[0];
}

//----------------------------------------------------------------------------
const forge::String& Story::GetRandomThought()
{
    static std::random_device rd;

    return m_RandomThoughts[rd() % m_RandomThoughts.size()];
}
