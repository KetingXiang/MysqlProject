
// MFCDatabase.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCDatabaseApp: 
// �йش����ʵ�֣������ MFCDatabase.cpp
//

class CMFCDatabaseApp : public CWinApp
{
public:
	CMFCDatabaseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCDatabaseApp theApp;