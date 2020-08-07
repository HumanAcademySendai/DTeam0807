#include "../StdAfx.h"
#include "title.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool TitleScene::Initialize()
{
	// TODO: Add your initialization logic here
	title = GraphicsDevice.CreateSpriteFromFile(_T("title.png"));

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void TitleScene::Finalize()
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
int TitleScene::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
    // TODO: Add your update logic here

	if (key.IsPressed(Keys_Return)) {
		return GAME_SCENE(new GameMain);
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void TitleScene::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();
	SpriteBatch.Begin();

	SpriteBatch.Draw(*title, Vector3(0, 0, 0));
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
