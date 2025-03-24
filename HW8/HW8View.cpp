// HW8View.cpp: CHW8View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW8.h"
#endif

#include "HW8Doc.h"
#include "HW8View.h"
#include "CEditVertexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHW8View

IMPLEMENT_DYNCREATE(CHW8View, CView)

BEGIN_MESSAGE_MAP(CHW8View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_TRIANGLE, &CHW8View::OnEditTriangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHW8View 构造/析构

CHW8View::CHW8View() noexcept
{
	// TODO: 在此处添加构造代码
	m_selectedVertex = -1;
	m_dragging = false;
	m_creating = false;
	m_creationStep = 0;
}

CHW8View::~CHW8View()
{
}

BOOL CHW8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW8View 绘图

void CHW8View::OnDraw(CDC* pDC)
{
	CHW8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->IsTriangleCreated() || m_creating) {
		// 绘制三角形
		POINT points[3];
		for (int i = 0; i < 3; i++) {
			CHW8Doc::Point vertex = pDoc->GetVertex(i);
			points[i].x = static_cast<LONG>(vertex.x);
			points[i].y = static_cast<LONG>(vertex.y);
		}

		// 绘制三角形边
		if (pDoc->IsTriangleCreated()) {
			pDC->Polygon(points, 3);
		}
		else if (m_creationStep > 0) {
			// 在创建过程中绘制已有的点和线
			for (int i = 0; i < m_creationStep; i++) {
				if (i > 0) {
					pDC->MoveTo(points[i - 1]);
					pDC->LineTo(points[i]);
				}
			}
		}

		// 绘制顶点标记
		for (int i = 0; i < (pDoc->IsTriangleCreated() ? 3 : m_creationStep); i++) {
			CRect rect = GetVertexRect(pDoc->GetVertex(i));
			pDC->Ellipse(rect);
		}
	}
}

// CHW8View 打印

BOOL CHW8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

// CHW8View 诊断

#ifdef _DEBUG
void CHW8View::AssertValid() const
{
	CView::AssertValid();
}

void CHW8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW8Doc* CHW8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW8Doc)));
	return (CHW8Doc*)m_pDocument;
}
#endif //_DEBUG

// CHW8View 消息处理程序

CRect CHW8View::GetVertexRect(const CHW8Doc::Point& point) const
{
	// 创建顶点周围的矩形区域，用于绘制和点击检测
	const int VERTEX_SIZE = 8; // 顶点大小
	int x = static_cast<int>(point.x);
	int y = static_cast<int>(point.y);
	return CRect(x - VERTEX_SIZE / 2, y - VERTEX_SIZE / 2,
		x + VERTEX_SIZE / 2, y + VERTEX_SIZE / 2);
}

int CHW8View::HitTest(CPoint point) const
{
	CHW8Doc* pDoc = GetDocument();
	if (!pDoc->IsTriangleCreated())
		return -1;

	// 检查是否点击了顶点
	for (int i = 0; i < 3; i++) {
		CRect rect = GetVertexRect(pDoc->GetVertex(i));
		if (rect.PtInRect(point))
			return i;
	}
	return -1; // 未选中任何顶点
}

void CHW8View::OnEditTriangle()
{
	// 打开对话框编辑三角形顶点坐标
	CHW8Doc* pDoc = GetDocument();
	if (!pDoc)
		return;

	CEditVertexDlg dlg;

	// 设置当前顶点坐标到对话框
	for (int i = 0; i < 3; i++) {
		CHW8Doc::Point pt = pDoc->GetVertex(i);
		switch (i) {
		case 0:
			dlg.m_x1 = pt.x;
			dlg.m_y1 = pt.y;
			break;
		case 1:
			dlg.m_x2 = pt.x;
			dlg.m_y2 = pt.y;
			break;
		case 2:
			dlg.m_x3 = pt.x;
			dlg.m_y3 = pt.y;
			break;
		}
	}

	// 显示对话框
	if (dlg.DoModal() == IDOK) {
		// 更新文档中的顶点坐标
		pDoc->SetVertex(0, dlg.m_x1, dlg.m_y1);
		pDoc->SetVertex(1, dlg.m_x2, dlg.m_y2);
		pDoc->SetVertex(2, dlg.m_x3, dlg.m_y3);

		// 如果三角形尚未创建，则标记为已创建
		if (!pDoc->IsTriangleCreated()) {
			pDoc->SetTriangleCreated(true);
		}

		// 标记文档已修改
		pDoc->SetModifiedFlag();

		// 刷新视图
		pDoc->UpdateAllViews(NULL);
	}
}

void CHW8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CHW8Doc* pDoc = GetDocument();
	if (!pDoc)
		return;

	if (pDoc->IsTriangleCreated()) {
		// 如果三角形已创建，检查是否点击了顶点
		m_selectedVertex = HitTest(point);
		if (m_selectedVertex >= 0) {
			m_dragging = true;
			SetCapture(); // 捕获鼠标
		}
	}
	else {
		// 如果三角形未创建，开始创建过程
		if (!m_creating) {
			m_creating = true;
			m_creationStep = 0;
		}

		// 设置当前步骤的顶点位置
		if (m_creationStep < 3) {
			pDoc->SetVertex(m_creationStep, point.x, point.y);
			m_creationStep++;

			// 如果已设置所有三个顶点，完成创建
			if (m_creationStep == 3) {
				pDoc->SetTriangleCreated(true);
				m_creating = false;
				m_creationStep = 0;
				pDoc->SetModifiedFlag();
			}

			Invalidate();
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

void CHW8View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_dragging) {
		m_dragging = false;
		ReleaseCapture(); // 释放鼠标捕获

		CHW8Doc* pDoc = GetDocument();
		if (pDoc) {
			pDoc->SetModifiedFlag();
		}
	}

	CView::OnLButtonUp(nFlags, point);
}

void CHW8View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_dragging && m_selectedVertex >= 0) {
		CHW8Doc* pDoc = GetDocument();
		if (pDoc) {
			// 更新被拖动顶点的位置
			pDoc->SetVertex(m_selectedVertex, point.x, point.y);

			// 刷新视图
			Invalidate();
		}
	}

	CView::OnMouseMove(nFlags, point);
}
