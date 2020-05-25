#ifndef __TILEMAP_H__
#define __TILEMAP_H__

struct SDL_Texture;
struct Collider;

enum TileType
{
	NONE = 0,
	BLOCK = 1,
	WALL = 2,
	DIAMOND = 3,

	MAX
};

class TileMap
{
public:
	TileMap();
	~TileMap();
	void level1();
	void LoadMap();
	void DrawMap();
	
public:

	int _map[15][13];
	
};

#endif // __TILEMAP_H__
