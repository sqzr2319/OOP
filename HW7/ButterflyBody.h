// ButterflyBody.h
#pragma once
#include <afxwin.h>

class CButterflyBody
{
public:
    CButterflyBody(COLORREF color);
    void Draw(CDC* pDC, CPoint center, int width, int height);

private:
    COLORREF m_color;
};