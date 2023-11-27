// Project11.h : main header file for the Project11 DLL
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
#include "acedCmdNF.h"


// CProject11App
// See Project11.cpp for the implementation of this class
//

class CProject11App : public CWinApp
{
public:
	CProject11App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void commandAndSysVar();
	DECLARE_MESSAGE_MAP()
};
