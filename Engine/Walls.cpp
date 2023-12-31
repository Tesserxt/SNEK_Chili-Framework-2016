#include "Walls.h"
#include <assert.h>

Walls::Walls(const RectF& in_innerbounds, int in_thickness, Color baseColor)
	:
	innerbounds(in_innerbounds),
	thickness(in_thickness)
{
	bevel.SetBaseColor(baseColor);
	assert(int(thickness) % 2 == 0);
	assert(innerbounds.GetExpanded(thickness).IsContainedBy(Graphics::GetScreenRect()));
}

void Walls::Draw(Graphics& gfx)
{
	int dim = DIM;
	bevel.DrawBevelFrame((innerbounds * dim ).GetExpanded(thickness) , thickness/2 , gfx);
}

const RectF& Walls::GetInnerBounds() const
{
	return innerbounds;
}
