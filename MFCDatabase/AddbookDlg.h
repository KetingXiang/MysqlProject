#pragma once


// CAddbookDlg 对话框

class CAddbookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddbookDlg)

public:
	CAddbookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddbookDlg();

// 对话框数据
	enum { IDD = IDD_ADDBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_bianhao;
	CString m_name;
	CString m_date;
	CString m_chubanshe;
	CString m_place;
	int m_num;
	afx_msg void OnBnClickedOk();
};
