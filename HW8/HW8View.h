#pragma once

class CHW8View : public CView
{
protected: // 仅从序列化创建
	CHW8View() noexcept;
	DECLARE_DYNCREATE(CHW8View)

	// 特性
public:
	CHW8Doc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 实现
public:
	virtual ~CHW8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_selectedVertex; // 选中的顶点，-1表示未选中
	bool m_dragging;      // 是否正在拖动
	bool m_creating;      // 是否正在创建三角形
	int m_creationStep;   // 创建三角形的步骤，0-2表示正在设置第几个顶点

	// 获取指定点周围的矩形区域
	CRect GetVertexRect(const CHW8Doc::Point& point) const;
	// 判断指定点是否在三角形顶点附近
	int HitTest(CPoint point) const;

	// 生成的消息映射函数
protected:
	afx_msg void OnEditTriangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HW8View.cpp 中的调试版本
inline CHW8Doc* CHW8View::GetDocument() const
{
	return reinterpret_cast<CHW8Doc*>(m_pDocument);
}
#endif
