// Drop.cpp
#include "pch.h"
#include "Drop.h"

CDrop::CDrop(COLORREF color) : m_color(color) {}

void CDrop::Draw(CDC* pDC, CPoint center, int radius)
{
    CBrush brush(m_color);
    CBrush* pOldBrush = pDC->SelectObject(&brush);

    pDC->Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);

    pDC->SelectObject(pOldBrush);
}