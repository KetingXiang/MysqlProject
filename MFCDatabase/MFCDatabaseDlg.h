
// MFCDatabaseDlg.h : ͷ�ļ�
//

#pragma once


// CMFCDatabaseDlg �Ի���
class CMFCDatabaseDlg : public CDialogEx
{
// ����
public:
	CMFCDatabaseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCDATABASE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedLoginTitleStatic();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangePasswordEdit2();
	CString m_Username;
	CString m_Password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedLogonButton2();
	afx_msg void OnBnClickedLoginButton1();
	afx_msg void OnEnChangeUsernameEdit1();
};
