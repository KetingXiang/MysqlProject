#pragma once


// CAddbookDlg �Ի���

class CAddbookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddbookDlg)

public:
	CAddbookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddbookDlg();

// �Ի�������
	enum { IDD = IDD_ADDBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
