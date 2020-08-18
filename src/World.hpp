#pragma once
#include "SFML/Graphics.hpp"
#include "Tile/StaticTile.hpp"
#include "Tile/AnimatedTile.hpp"
#include "Entity/Player.hpp"
#include "Cursor.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime, sf::RenderWindow* window, sf::View* view);
	void Draw(sf::RenderWindow* window);

	void MovePlayer(sf::Vector2f aDistance, double& deltaTime);
	Player* GetPlayer();

private:
	Player* player;
	std::vector<Tile::Tile*>* tiles;
	Cursor* cursor;
	Tile::Tile* CheckTiles(sf::Vector2f mousePos);
	bool CheckTileCollision(sf::FloatRect& aRect);

	sf::Texture* tileTexture;
	sf::Texture* animTexture;
};