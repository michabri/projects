#pragma once
// location in the matrix
struct Location 
{
	int row;
	int col;
};

//window properties
constexpr auto WINDOW_WIDTH = 1000.f;
constexpr auto WINDOW_HEIGHT = 800.f;

//board properties
constexpr auto SPACE = 5.f;
constexpr auto BOARD_SIZE = 11.f;
constexpr auto BOARD_WIDTH = 600.f;
constexpr auto BOARD_HEIGHT = 600.f;
constexpr auto OBJECT_SIZE_PIXEL = 100.f;
constexpr auto RADIUS_TILE = BOARD_WIDTH / (BOARD_SIZE + SPACE) / 1.5;