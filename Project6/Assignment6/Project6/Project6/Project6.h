// Project6.h : main header file for the Project6 DLL
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


// CProject6App
// See Project6.cpp for the implementation of this class
//

class CProject6App : public CWinApp
{
public:
	CProject6App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void listObjects();
	DECLARE_MESSAGE_MAP()
};
