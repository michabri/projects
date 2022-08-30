#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "box2d/box2d.h"
#include "Resources.h"
#include "Socket.h"

constexpr auto WINDOW_WIDTH = 1600.f;
constexpr auto WINDOW_HEIGHT = 800.f;
constexpr auto STATIC_OBJECT_SIZE_PIXEL = 100.f;
constexpr auto PLAYER_WIDTH = 48.f;
constexpr auto STAGE_TIME = 60.f;
constexpr auto BAR_SIZE = 100.f;
constexpr auto SHOT_WIDTH = 5.f;
constexpr auto SHOT_HEIGHT = -50;

enum entity 
{
    BORDER_FLOOR = 0x0001,
    BORDER_CEILING = 0x0002,
    WALL = 0x0004,
    BALL = 0x0008,
    WEAPON = 0x0010,
    PLAYER = 0x0020,
    GIFT = 0x0040,
    SHIELD = 0x0080,
};
enum background
{
    BACKGROUND,
    HELP,
    BACKGROUND_FADE
};

enum gameObjects 
{
    RED_BALL,
    WALL_GO,
    GATE_GO,
    PURPLE_BALL,
    BLUE_BALL,
    ORANGE_BALL,
    NORMAL_WEAPON_GIFT_GO,
    HOOK_WEAPON_GIFT_GO,
    LASER_WEAPON_GIFT_GO,
    GREEN_CLOCK_GO,
    RED_CLOCK_GO,
    SHIELD_GO,
    LIFE_GO,
    X_LIFE_GO,
    NORMAL_WEAPON_GO,
    HOOK_WEAPON_GO,
    LASER_WEAPON_GO
};

enum ballRadius 
{
    MEGA_BIG = 100,
    BIG = 50,
    MEDIUM = 25,
    SMALL = 12,
};

enum pauseButtons
{
    HOME, 
    RESTART, 
    MUSIC
};

enum gift
{
    NORMAL_WEAPON, 
    HOOK_WEAPON,
    LASER_WEAPON,
    SHIELD_GIFT,
    GREEN_CLOCK,
    RED_CLOCK,
    LIFE
};

enum flows
{
    BATMAN_FLOW,
    ROBIN_FLOW
};

enum sounds
{
    PLAYER_HIT_SOUND,
    GAME_OVER,
};

enum music_song
{
    BACKGROUND_SONG,
    MENU_SONG
};