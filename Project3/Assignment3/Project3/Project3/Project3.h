// Project3.h : main header file for the Project3 DLL
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

// CProject3App
// See Project3.cpp for the implementation of this class
//

class CProject3App : public CWinApp
{
public:
	CProject3App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void Greetings();

	DECLARE_MESSAGE_MAP()
};
