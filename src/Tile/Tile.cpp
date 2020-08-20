#include "Tile.hpp"
#include "TileList.hpp"

namespace Tile {
	Tile::Tile(sf::Vector2f& aPosition, TileType aType, bool aCollidesWithEntities) :
		sprite(nullptr),
		texture(nullptr),
		hitBox(sf::FloatRect(aPosition, sf::Vector2f(32.0f, 32.0f))),		
		position(aPosition),
		isVisible(true),
		type(aType),
		changeTileTypeFlag(false),
		typeToChangeTo(TileType::Empty),
		dropItemFlag(false),
		itemTypeToDrop(Item::ItemType::None),
		collidesWithEntities(aCollidesWithEntities)
	{}

	void Tile::Draw(sf::RenderWindow* window) {}
	void Tile::Update(double& deltaTime) {}

	void Tile::OnLeftClick(Cursor* cursor) {}
	void Tile::OnRightClick(Cursor* cursor)	{}
	void Tile::OnWorldEvent() {}


	// Empty Tile ------------------------------
	Empty::Empty(sf::Vector2f& aPosition) :
		Tile(aPosition, TileType::Empty)
	{}

	Empty::~Empty() {}

	void Empty::OnWorldEvent() {
		changeTileTypeFlag = true;
		typeToChangeTo = TileType::Stone;
	}

	Tile* CreateNewTile(sf::Vector2f aPosition, TileType aType)	{
		switch (aType)
		{
		case TileType::Empty:
			return new Empty(aPosition);
			break;

		case TileType::Stone:
			return new Stone(aPosition);
			break;

		case TileType::Floor:
			return new Floor(aPosition);
			break;

		default:
			return nullptr;
			break;
		}
	}
}