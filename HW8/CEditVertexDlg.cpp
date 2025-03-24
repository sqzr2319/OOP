// CEditVertexDlg.cpp : 实现文件
//

#include "pch.h"
#include "HW8.h"
#include "CEditVertexDlg.h"
#include "afxdialogex.h"

// CEditVertexDlg 对话框

IMPLEMENT_DYNAMIC(CEditVertexDlg, CDialogEx)

CEditVertexDlg::CEditVertexDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDIT_VERTEX, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(0)
	, m_y2(0)
	, m_x3(0)
	, m_y3(0)
{
}

CEditVertexDlg::~CEditVertexDlg()
{
}

void CEditVertexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
	DDX_Text(pDX, IDC_EDIT_X3, m_x3);
	DDX_Text(pDX, IDC_EDIT_Y3, m_y3);
}

BEGIN_MESSAGE_MAP(CEditVertexDlg, CDialogEx)
END_MESSAGE_MAP()
