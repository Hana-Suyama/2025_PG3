#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
public:

	void Size() override;

	void Draw() override;

	void SetWidthHeight(float width, float height) { width_ = width; height_ = height; }

private:

	float width_ = 3.0f;
	float height_ = 4.5f;

	float size_;

};

