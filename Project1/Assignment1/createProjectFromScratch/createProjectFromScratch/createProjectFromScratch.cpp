// createProjectFromScratch.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "createProjectFromScratch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"


extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU2014 project...\n"));
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

// CcreateProjectFromScratchApp

BEGIN_MESSAGE_MAP(CcreateProjectFromScratchApp, CWinApp)
END_MESSAGE_MAP()


// CcreateProjectFromScratchApp construction

CcreateProjectFromScratchApp::CcreateProjectFromScratchApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CcreateProjectFromScratchApp object

CcreateProjectFromScratchApp theApp;


// CcreateProjectFromScratchApp initialization

BOOL CcreateProjectFromScratchApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
