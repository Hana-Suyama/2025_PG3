#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:

	void Size() override;

	void Draw() override;

	void SetRadius(float radius) { radius_ = radius; }

private:

	float radius_ = 5.0f;

	float size_;

};

