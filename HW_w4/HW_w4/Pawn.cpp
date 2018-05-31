#include "stdafx.h"
#include "Pawn.h"


CPawn::~CPawn()
{
}

void CPawn::Draw(CDC & dc)
{
	dc.Rectangle(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
}
