// AddbookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDatabase.h"
#include "AddbookDlg.h"
#include "afxdialogex.h"
#include "conio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <winsock.h>
#include "mysql.h"
#include <iostream>
#include<locale.h>
using namespace std;

// CAddbookDlg 对话框

IMPLEMENT_DYNAMIC(CAddbookDlg, CDialogEx)

CAddbookDlg::CAddbookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddbookDlg::IDD, pParent)
	, m_bianhao(_T(""))
	, m_name(_T(""))
	, m_date(_T(""))
	, m_chubanshe(_T(""))
	, m_place(_T(""))
	, m_num(0)
{

}

CAddbookDlg::~CAddbookDlg()
{
}

void CAddbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_bianhao);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_date);
	DDX_Text(pDX, IDC_EDIT2, m_chubanshe);
	DDX_Text(pDX, IDC_EDIT6, m_place);
	DDX_Text(pDX, IDC_EDIT5, m_num);
}


BEGIN_MESSAGE_MAP(CAddbookDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddbookDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddbookDlg 消息处理程序


void CAddbookDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	MYSQL mysql;

	//初始化数据库
	mysql_init(&mysql);
	//链接数据库，进行用户名和密码的验证
	if (mysql_real_connect(&mysql, "localhost", "mysql", "123", "BookLending",
		3306, 0, CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS)) {
		mysql_query(&mysql, "set names utf8");
		//_cprintf("%s,%s,%s,%s,%s\n", m_logonname, m_logonxuehao, m_logonxibie, m_logonzhuanye, m_logonmima);
		//_cprintf("size: %d\n", m_logonname.GetLength());
		char strquery[100] = "insert into canLend values ('";
		//声明标识符
		USES_CONVERSION;
		//调用函数，T2A和W2A均支持ATL和MFC中的字符转换
		char* pFileName = T2A(this->m_bianhao);
		strcat_s(strquery, pFileName);
		strcat_s(strquery, "','");

		char* pFileName2 = T2A(m_name);
		strcat_s(strquery, pFileName2);
		strcat_s(strquery, "','");

		char* pFileName3 = T2A(m_date);
		strcat_s(strquery, pFileName3);
		strcat_s(strquery, "','");

		char* pFileName4 = T2A(m_chubanshe);
		strcat_s(strquery, pFileName4);
		strcat_s(strquery, "','");

		char* pFileName5 = T2A(m_place);
		strcat_s(strquery, pFileName5);
		strcat_s(strquery, "','");

		char s[10];
		_itoa_s(m_num, s, 10);
		strcat_s(strquery, s);
		strcat_s(strquery, "')");

		int num = mysql_query(&mysql, strquery);
		_cprintf("num  %d\n", num);
		_cprintf("%s\n", strquery);
		if (num == 0) {		//返回0执行成功
			MessageBox(_T("新增成功"), _T("提示"));
			mysql_close(&mysql);
		}
		else {
			MessageBox(_T("未能新增成功"), _T("提示"));
		}

	}
	else {
		MessageBox(_T("连接数据库失败"), _T("提示"));
	}


	CDialogEx::OnOK();
}
