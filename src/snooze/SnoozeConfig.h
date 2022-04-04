#pragma once

//----------------------------------------------------------------------------
struct SnoozeConfig
{
    static constexpr u32 TimerMaxTimeMs = 10000;
    static constexpr f32 MiniGameTimeRatioToSpawn = 0.1f;
    static constexpr f32 SpeechCharactersPerSecond = 42.0f;

    static constexpr u32 ToolSpawnPointCount = 6;
    static constexpr forge::Vector3f ToolSpawnPoints[ToolSpawnPointCount] =
    {
        { 40.f, 40.f, 10.f },
        { 56.f, 56.f, 10.f },
        { 40.f, 56.f, 10.f },
        { 56.f, 40.f, 10.f },
        { 41.f, 50.f,  1.f },
        { 54.f, 49.f,  1.f }
    };

    static constexpr u32 MobSpawnPointCount = 1;
    static constexpr forge::Vector3f MobSpawnPoints[MobSpawnPointCount] =
    {
        // TODO: fill mob spawn points
        { 40.f, 40.f, 10.f }
    };
};
