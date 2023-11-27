// Project11.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project11.h"

// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"
#include "acedCmdNF.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CProject11App::commandAndSysVar()
{
	// Create a variable of the result buffer type
	struct resbuf rb, rb1;
	// Get the current value of the CIRCLERAD system variable
	acedGetVar(_T("CIRCLERAD"), &rb);
	acutPrintf(_T("\nCurrent CIRCLERAD: %.2f\n"), rb.resval);
	// Define the center point for the circle
	ads_point pt;
	pt[X] = 2.5; pt[Y] = 3.75; pt[Z] = 0.0;
	// Define the radius of the circle
	double rrad = 2.75;
	// Provide all values to the CIRCLE command
	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTPOINT, pt,
		RTREAL, rrad, RTNONE) != RTNORM)
	{
		acutPrintf(_T("\nError: CIRCLE command failed."));
	}

		// Pause for the center point
		if (acedCommandS(RTSTR, _T("._CIRCLE"), RTSTR, PAUSE,
			RTREAL, rrad, RTNONE) != RTNORM)
		{
			acutPrintf(_T("\nError: CIRCLE command failed."));
		}
	// Set the value of CIRCLERAD to the previous value
	rb1.restype = RTREAL;
	rb1.resval.rreal = rb.resval.rreal;
	acedSetVar(_T("CIRCLERAD"), &rb1);
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU2014 project...\n"));
		acedRegCmds->addCommand(_T("AUCommands"), _T("CommandAndSysVar"), _T("CommandAndSysVar"), ACRX_CMD_MODAL, &CProject11App::commandAndSysVar);
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

// CProject11App

BEGIN_MESSAGE_MAP(CProject11App, CWinApp)
END_MESSAGE_MAP()


// CProject11App construction

CProject11App::CProject11App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProject11App object

CProject11App theApp;


// CProject11App initialization

BOOL CProject11App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
