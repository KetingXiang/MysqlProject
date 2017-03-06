
// MFCDatabaseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDatabase.h"
#include "MFCDatabaseDlg.h"
#include "afxdialogex.h"
#include "Logon.h"
#include "PersonDlg.h"
#include "conio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <winsock.h>
#include "mysql.h"
#include <iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCDatabaseDlg 对话框



CMFCDatabaseDlg::CMFCDatabaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDatabaseDlg::IDD, pParent)
	, m_Username(_T(""))
	, m_Password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDatabaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME_EDIT1, m_Username);
	DDX_Text(pDX, IDC_PASSWORD_EDIT2, m_Password);
}

BEGIN_MESSAGE_MAP(CMFCDatabaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCDatabaseDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_LOGIN_TITLE_STATIC, &CMFCDatabaseDlg::OnStnClickedLoginTitleStatic)
	ON_EN_CHANGE(IDC_USERNAME_EDIT1, &CMFCDatabaseDlg::OnEnChangeUsernameEdit1)
	ON_EN_CHANGE(IDC_PASSWORD_EDIT2, &CMFCDatabaseDlg::OnEnChangePasswordEdit2)
	ON_BN_CLICKED(IDC_LOGON_BUTTON2, &CMFCDatabaseDlg::OnBnClickedLogonButton2)
	ON_BN_CLICKED(IDC_LOGIN_BUTTON1, &CMFCDatabaseDlg::OnBnClickedLoginButton1)
END_MESSAGE_MAP()


// CMFCDatabaseDlg 消息处理程序

BOOL CMFCDatabaseDlg::OnInitDialog()
{
	AllocConsole();
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	// comb1
	


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCDatabaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDatabaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDatabaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDatabaseDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCDatabaseDlg::OnStnClickedLoginTitleStatic()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMFCDatabaseDlg::OnEnChangeUsernameEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCDatabaseDlg::OnEnChangePasswordEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCDatabaseDlg::OnBnClickedLoginButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	setlocale(LC_ALL, "chs");
	//_cprintf("row: %d\n", rowcount);
	//_cprintf("col: %d\n", num_fields);
	/*_cprintf("num  %d\n", num);
	_cprintf("%s\n", strquery);*/
	MYSQL mysql;
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	//初始化数据库
	mysql_init(&mysql);
	//链接数据库，进行用户名和密码的验证
	if (mysql_real_connect(&mysql, "localhost", "mysql", "123", "BookLending", 
		3306, 0, CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS)) {
		mysql_query(&mysql, "set names utf8");

		char strquery[100] = "select spw from stu where sno = '";
		USES_CONVERSION;
		char * p = T2A(m_Username);
		strcat_s(strquery, p);
		strcat_s(strquery, "'");
		
		int num = mysql_query(&mysql, strquery);
		if (num == 0) {		//返回0执行成功
			result = mysql_store_result(&mysql);			//获取查询结果
			int rowcount = mysql_num_rows(result);			//行数
			int num_fields = mysql_field_count(&mysql);		//列数							
			row = mysql_fetch_row(result);					//获取一行数据

			if (row != NULL && row[0] == m_Password) {
				MessageBox(_T("登录成功"), _T("提示"));
				this->ShowWindow(SW_HIDE);
				CPersonDlg person;
				person.person_id = m_Username;
				person.DoModal();
			}
			else if (row == NULL){
				MessageBox(_T("当前用户不存在"), _T("提示"));
			}
			else {
				MessageBox(_T("密码错误"), _T("提示"));
			}
			
		}
		else {
			MessageBox(_T("登录失败"), _T("提示"));
		}
		
		mysql_free_result(result);
	}
	else {
		MessageBox(_T("连接数据库失败"), _T("提示"));
	}
	//mysql_close(&mysql);
		
}


void CMFCDatabaseDlg::OnBnClickedLogonButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//this->ShowWindow(SW_HIDE);
	INT_PTR nRes;
	CLogon logon;
	nRes = logon.DoModal();
	if (IDOK == nRes) {
		this->m_Username = logon.m_logonname;
		this->m_Password = "";
		UpdateData(false);
	}
}






