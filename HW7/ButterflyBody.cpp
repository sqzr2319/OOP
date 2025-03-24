// ButterflyBody.cpp
#include "pch.h"
#include "ButterflyBody.h"

CButterflyBody::CButterflyBody(COLORREF color) : m_color(color) {}

void CButterflyBody::Draw(CDC* pDC, CPoint center, int width, int height)
{
    CBrush brush(m_color);
    CBrush* pOldBrush = pDC->SelectObject(&brush);

    pDC->Ellipse(center.x - width / 2, center.y - height / 2, center.x + width / 2, center.y + height / 2);

    pDC->SelectObject(pOldBrush);
}