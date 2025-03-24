// ButterflyWing.cpp
#include "pch.h"
#include "ButterflyWing.h"

CButterflyWing::CButterflyWing(COLORREF color) : m_color(color) {}

void CButterflyWing::Draw(CDC* pDC, CPoint center, int width, int height)
{
    CBrush brush(m_color);
    CBrush* pOldBrush = pDC->SelectObject(&brush);

    POINT points[4] = {
        {center.x, center.y - height / 2},
        {center.x + width / 2, center.y},
        {center.x, center.y + height / 2},
        {center.x - width / 2, center.y}
    };
    pDC->Polygon(points, 4);

    pDC->SelectObject(pOldBrush);
}