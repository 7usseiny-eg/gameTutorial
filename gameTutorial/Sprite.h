#pragma once
#include <GL/glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void draw();
	void init(float x, float y, float width, float height);
private:
	int _x;
	int _y;
	int _width;
	int _height;
	
	GLuint _vboID;

};

