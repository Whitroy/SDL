#include"Tile.h"
#include"Application4.h"
#include<string>
namespace SDLChapter4
{
	Tile::Tile(Application4* game)
		:Actor{game}, mParent{ nullptr },
		f{ 0.0f }, g{ 0.0f }, h{ 0.0f }, mBlocked{ false },
		mSprite{ nullptr }, mTileState{ TileState::EDefault },
		mSelected(false)
	{
		mSprite = new ::SpriteComponent(this);
		UpdateTexture();
	}

	void Tile::SetTileState(TileState state)
	{
		mTileState = state;
		UpdateTexture();
	}

	void Tile::ToggleSelect()
	{
		mSelected = !mSelected;
		UpdateTexture();
	}

	void Tile::UpdateTexture()
	{
		std::string text{};
		switch (mTileState)
		{
		case TileState::EStart:
			text = "Assests/TileTan.png";
			break;
		case TileState::EBase:
			text = "Assests/TileGreen.png";
			break;
		case TileState::EPath:
			if (mSelected)
				text = "Assests/TileGreySelected.png";
			else
				text = "Assests/TileGrey.png";
			break;
		case TileState::EDefault:
		default:
			if (mSelected)
				text = "Assests/TileBrownSelected.png";
			else
				text = "Assests/TileBrown.png";
			break;
		}
		mSprite->SetTexture(GetGame()->GetTexture(text));
	}
}