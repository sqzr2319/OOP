// Drop.h
#pragma once
#include <afxwin.h>

class CDrop
{
public:
    CDrop(COLORREF color);
    void Draw(CDC* pDC, CPoint center, int radius);

private:
    COLORREF m_color;
};