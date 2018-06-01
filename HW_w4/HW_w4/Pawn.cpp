#include "stdafx.h"
#include "Pawn.h"


CPawn::~CPawn()
{
}

void CPawn::Draw(CDC & dc)
{
	if(isCircle) dc.Ellipse(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
	else dc.Rectangle(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
}
