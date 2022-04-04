#include <snooze/Precomp.h>
#include <snooze/Story.h>
#include <random>

#include <iostream>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
void Story::InitInstance()
{
    m_StoryAdvancement = 0;

    m_Storylines.push_back({ "Ha, what a beautiful day!" });
    m_Storylines.push_back({ "The perfect time to laze around,",
                             "no more pressure, none."});
    m_Storylines.push_back({ "And I get to be here,",
                             "with you!" });
    m_Storylines.push_back({ "Truly something worth enjoying to the\nfullest." });
    m_Storylines.push_back({ "Though these dreamlike scalawags\nwander while wide awake..."});
    m_Storylines.push_back({ "Still drowsy maybe?",
                             "From these last days?"});
    m_Storylines.push_back({ "You have to say that this LDJam was\ntiresome.",
                             "Fun for sure,",
                             "tiresome nonetheless." });
    m_Storylines.push_back({ "Sliding some extra hours of sleep\nsoon would not be such a bad idea.",
                             "Selfcare *is* important!"});
    m_Storylines.push_back({ "Especially that in the end there is still so\nmuch more new acquaintances\nneeded to be made." });
    m_Storylines.push_back({ "After all,",
                             "I am only one in plenty..."});
    m_Storylines.push_back({ "You are the true hero",
                             "and I am just an humble game jam\nproject looking for company." });
    
    m_RandomThoughts.push_back({ "One more minute please..." });
    m_RandomThoughts.push_back({ "It's so comfy with you." });
    m_RandomThoughts.push_back({ "Is it time already?" });
    m_RandomThoughts.push_back({ "Ok, one last time, promised!" });
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
