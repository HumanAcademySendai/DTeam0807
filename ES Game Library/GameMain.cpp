// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	player = GraphicsDevice.CreateSpriteFromFile(_T("Chara.png"));
	map = GraphicsDevice.CreateSpriteFromFile(_T("map w.png"));

	player_x = 550.0f;
	player_y = 320.0f;
	player_spd = 4.0f;


	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here
	
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here
	KeyboardState key = Keyboard->GetState();

	if (key.IsKeyDown(Keys_Right))
	{
		player_x += player_spd;
	}
	if (key.IsKeyDown(Keys_Left))
	{
		player_x -= player_spd;
	}

	if (key.IsKeyDown(Keys_Down))
	{
		player_y += player_spd;
	}
	if (key.IsKeyDown(Keys_Up))
	{
		player_y -= player_spd;
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();

	SpriteBatch.Draw(*player, Vector3(player_x, player_y, -10.0f));
	SpriteBatch.Draw(*map, Vector3(0.0f, 0.0f, 0.0f));

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
