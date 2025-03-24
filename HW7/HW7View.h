
// HW7View.h: CHW7View 类的接口
//

#pragma once


class CHW7View : public CView
{
protected: // 仅从序列化创建
	CHW7View() noexcept;
	DECLARE_DYNCREATE(CHW7View)

// 特性
public:
	CHW7Doc* GetDocument() const;

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
	virtual ~CHW7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HW7View.cpp 中的调试版本
inline CHW7Doc* CHW7View::GetDocument() const
   { return reinterpret_cast<CHW7Doc*>(m_pDocument); }
#endif

