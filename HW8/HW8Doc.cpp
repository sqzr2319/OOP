// HW8Doc.cpp: CHW8Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW8.h"
#endif

#include "HW8Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHW8Doc

IMPLEMENT_DYNCREATE(CHW8Doc, CDocument)

BEGIN_MESSAGE_MAP(CHW8Doc, CDocument)
END_MESSAGE_MAP()

// CHW8Doc 构造/析构

CHW8Doc::CHW8Doc() noexcept
{
	// TODO: 在此添加一次性构造代码
	m_triangleCreated = false;
	// 初始化顶点位置
	for (int i = 0; i < 3; i++) {
		m_vertices[i].x = 0;
		m_vertices[i].y = 0;
	}
}

CHW8Doc::~CHW8Doc()
{
}

void CHW8Doc::SetVertex(int index, double x, double y)
{
	if (index >= 0 && index < 3) {
		m_vertices[index].x = x;
		m_vertices[index].y = y;
	}
}

CHW8Doc::Point CHW8Doc::GetVertex(int index) const
{
	if (index >= 0 && index < 3) {
		return m_vertices[index];
	}
	return Point(0, 0);
}

BOOL CHW8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	m_triangleCreated = false;
	// 重置顶点位置
	for (int i = 0; i < 3; i++) {
		m_vertices[i].x = 0;
		m_vertices[i].y = 0;
	}

	return TRUE;
}

// CHW8Doc 序列化

void CHW8Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// 存储三角形数据
		ar << m_triangleCreated;
		for (int i = 0; i < 3; i++) {
			ar << m_vertices[i].x << m_vertices[i].y;
		}
	}
	else
	{
		// 加载三角形数据
		ar >> m_triangleCreated;
		for (int i = 0; i < 3; i++) {
			ar >> m_vertices[i].x >> m_vertices[i].y;
		}
	}
}

// CHW8Doc 诊断

#ifdef _DEBUG
void CHW8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHW8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
