// ButterflyWing.h
#pragma once
#include <afxwin.h>

class CButterflyWing
{
public:
    CButterflyWing(COLORREF color);
    void Draw(CDC* pDC, CPoint center, int width, int height);

private:
    COLORREF m_color;
};