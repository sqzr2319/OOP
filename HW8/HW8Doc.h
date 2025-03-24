#pragma once

class CHW8Doc : public CDocument
{
protected: // 仅从序列化创建
	CHW8Doc() noexcept;
	DECLARE_DYNCREATE(CHW8Doc)

	// 特性
public:
	struct Point {
		double x;
		double y;

		Point() : x(0), y(0) {}
		Point(double _x, double _y) : x(_x), y(_y) {}
	};

	Point m_vertices[3]; // 三角形的三个顶点
	bool m_triangleCreated; // 标记三角形是否已创建

	// 操作
public:
	void SetVertex(int index, double x, double y);
	Point GetVertex(int index) const;
	bool IsTriangleCreated() const { return m_triangleCreated; }
	void SetTriangleCreated(bool created) { m_triangleCreated = created; }

	// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	//virtual void InitializeSearchContent();
	//virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// 实现
public:
	virtual ~CHW8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	//void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
