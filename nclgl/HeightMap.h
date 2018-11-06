#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Mesh.h"

#define RAW_WIDTH 257
#define RAW_HEIGHT 257

#define HEIGHTMAP_X 160.0f
#define HEIGHTMAP_Z 160.0f
#define HEIGHTMAP_Y 12.5f
#define HEIGHTMAP_TEX_X 10.0f / 160.0f
#define HEIGHTMAP_TEX_Z 10.0f / 160.0f

class HeightMap : public Mesh {
 public:
	HeightMap(std::string name);
	~HeightMap(void) {};};