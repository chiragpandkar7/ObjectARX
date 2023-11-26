// Project5.h : main header file for the Project5 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"

// CProject5App
// See Project5.cpp for the implementation of this class
//

class CProject5App : public CWinApp
{
public:
	CProject5App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void makeLayer();
	DECLARE_MESSAGE_MAP()
};
