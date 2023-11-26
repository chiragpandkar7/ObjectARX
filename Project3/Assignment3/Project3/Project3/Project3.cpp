// Project3.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project3.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"

void CProject3App::Greetings()
{
	acutPrintf(_T("\nHello World!!!"));
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU2014 project...\n"));
		acedRegCmds->addCommand(_T("AUCommands"), _T("Greetings"),_T("Greetings"), ACRX_CMD_MODAL, &CProject3App::Greetings);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU2014 project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CProject3App

BEGIN_MESSAGE_MAP(CProject3App, CWinApp)
END_MESSAGE_MAP()


// CProject3App construction

CProject3App::CProject3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProject3App object

CProject3App theApp;


// CProject3App initialization

BOOL CProject3App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
