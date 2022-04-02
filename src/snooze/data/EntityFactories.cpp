
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "EntityFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    forge::Entity* SnoozeButtonFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::SnoozeButton);

        data->SetSize(5.12, 2.04, 0);
data->AddComponent<SnoozableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::ForgeSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::Alarm);

        data->SetSize(20, 20, 2);
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmNeutralSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmScrewFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::AlarmScrew);

        data->SetSize(20, 20, 2);
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmScrewSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmButtonNeutralFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::AlarmButtonNeutral);

        data->SetSize(20, 20, 1);
data->AddComponent<SnoozableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonNeutralSprite));

        return data;
    }

    }}}
