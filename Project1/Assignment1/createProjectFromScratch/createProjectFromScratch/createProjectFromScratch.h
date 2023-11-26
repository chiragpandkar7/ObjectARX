// createProjectFromScratch.h : main header file for the createProjectFromScratch DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CcreateProjectFromScratchApp
// See createProjectFromScratch.cpp for the implementation of this class
//

class CcreateProjectFromScratchApp : public CWinApp
{
public:
	CcreateProjectFromScratchApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
