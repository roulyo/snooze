#pragma once

//----------------------------------------------------------------------------
struct SnoozeConfig
{
    static constexpr u32 TimerMaxTimeMs = 100000;
    static constexpr f32 MiniGameTimeRatioToSpawn = 0.01f;
    static constexpr f32 SpeechCharactersPerSecond = 42.0f;

    static constexpr u32 StoryDisplayTimeMs = 2000;
    static constexpr u32 ThoughtDisplayTimeMs = 1000;

    static constexpr u32 PostGameTimeMs = 15000;

    static constexpr u32 KeysSpawnPointCount = 6;
    static constexpr forge::Vector3f KeysSpawnPoints[KeysSpawnPointCount] =
    {
        { 40.f, 40.f, 10.f },
        { 56.f, 56.f, 10.f },
        { 40.f, 56.f, 10.f },
        { 56.f, 40.f, 10.f },
        { 41.f, 50.f, 0.1f },
        { 54.f, 49.f, 0.1f }
    };

    static constexpr u32 ToolSpawnPointCount = 4;
    static constexpr forge::Vector3f ToolSpawnPoints[ToolSpawnPointCount] =
    {
        { 40.f, 40.f, 10.f },
        { 56.f, 56.f, 10.f },
        { 40.f, 56.f, 10.f },
        { 56.f, 40.f, 10.f },
    };

    static constexpr u32 MobSpawnPointCount = 8;
    static constexpr forge::Vector3f MobSpawnPoints[MobSpawnPointCount] =
    {
        { 55.f, 55.f, 10.f },
        { 40.f, 40.f, 10.f },
        { 40.f, 56.f, 10.f },
        { 55.f, 40.f, 10.f },
        { 50.f, 40.f, 0.1f },
        { 54.f, 49.f, 0.1f },
        { 54.f, 49.f, 10.f },
        { 40.f, 45.f, 10.f },
    };
};
