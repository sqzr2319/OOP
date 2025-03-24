
// HW7View.cpp: CHW7View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW7.h"
#endif

#include "HW7Doc.h"
#include "HW7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "ButterflyWing.h"
#include "ButterflyBody.h"
#include "Drop.h"

// CHW7View

IMPLEMENT_DYNCREATE(CHW7View, CView)

BEGIN_MESSAGE_MAP(CHW7View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CHW7View 构造/析构

CHW7View::CHW7View() noexcept
{
	// TODO: 在此处添加构造代码

}

CHW7View::~CHW7View()
{
}

BOOL CHW7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW7View 绘图

void CHW7View::OnDraw(CDC* pDC)
{
    CHW7Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // 设置图案的中心点和大小
    CPoint center(200, 200);
    int wingWidth = 100;
    int wingHeight = 150;
    int bodyWidth = 30;
    int bodyHeight = 100;
    int dropRadius = 20;

    // 创建图形对象
    CButterflyWing leftWing(RGB(173, 216, 230)); // 浅蓝色
    CButterflyWing rightWing(RGB(72, 61, 139)); // 深蓝色
    CButterflyBody body(RGB(0, 0, 0)); // 黑色
    CDrop drop(RGB(0, 191, 255)); // 深天蓝色

    // 绘制图形
    leftWing.Draw(pDC, CPoint(center.x - wingWidth / 2, center.y), wingWidth, wingHeight);
    rightWing.Draw(pDC, CPoint(center.x + wingWidth / 2, center.y), wingWidth, wingHeight);
    body.Draw(pDC, center, bodyWidth, bodyHeight);
    drop.Draw(pDC, CPoint(center.x, center.y + bodyHeight / 2 + dropRadius), dropRadius);
}


// CHW7View 打印

BOOL CHW7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW7View 诊断

#ifdef _DEBUG
void CHW7View::AssertValid() const
{
	CView::AssertValid();
}

void CHW7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW7Doc* CHW7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW7Doc)));
	return (CHW7Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW7View 消息处理程序
