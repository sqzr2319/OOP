#pragma once

// CEditVertexDlg �Ի���

class CEditVertexDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditVertexDlg)

public:
	CEditVertexDlg(CWnd* pParent = nullptr);   // ��׼���캯��
	virtual ~CEditVertexDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDIT_VERTEX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_x1;
	double m_y1;
	double m_x2;
	double m_y2;
	double m_x3;
	double m_y3;
};
