// Project7.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project7.h"
// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CProject7App :: inputLine()
{
	// Get the current space block
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForWrite);
	// Create 2 variables of the old point data type
	ads_point pt1, pt2;
	// Prompt for the first point
	if (RTNORM == acedGetPoint(NULL, _T("\nSpecify first point: "), pt1))
	{
		AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);
		// Prompt for the second point
		if (RTNORM == acedGetPoint(pt1, _T("\nSpecify second point: "), pt2))
		{
				AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);
			// Create and append the new Line object
			AcDbLine* pLine = new AcDbLine(startPt, endPt);
			pBlockTableRecord->appendAcDbEntity(pLine);
			// Close the block table record and the Line object
			pBlockTableRecord->close();
			pLine->close();
		}
	}
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU2014 project...\n"));
		acedRegCmds->addCommand(_T("AUCommands"), _T("InputLine"), _T("InputLine"), ACRX_CMD_MODAL, &CProject7App::inputLine);
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

// CProject7App

BEGIN_MESSAGE_MAP(CProject7App, CWinApp)
END_MESSAGE_MAP()


// CProject7App construction

CProject7App::CProject7App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProject7App object

CProject7App theApp;


// CProject7App initialization

BOOL CProject7App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
