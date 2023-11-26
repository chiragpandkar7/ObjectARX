// Project4.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project4.h"
// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CProject4App :: addLine()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Open the Block Table for read-only
	AcDbBlockTable* pBlockTable;
	pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
	// Get the Model Space block
	AcDbBlockTableRecord* pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,
		pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();
	// Define the points that will be used to define the Line object
	AcGePoint3d startPt(7.0, 3.0, 0.0);
	AcGePoint3d endPt(11.0, 3.0, 0.0);
	// Create the new Line object in memory
	AcDbLine* pLine = new AcDbLine(startPt, endPt);
	// Add the new Line object to Model space
	pBlockTableRecord->appendAcDbEntity(pLine);
	// Close the Model space block
	pBlockTableRecord->close();
	// Close the new line object
	pLine->close();
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU2014 project...\n"));
		acedRegCmds->addCommand(_T("AUCommands"), _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CProject4App::addLine);
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

// CProject4App

BEGIN_MESSAGE_MAP(CProject4App, CWinApp)
END_MESSAGE_MAP()


// CProject4App construction

CProject4App::CProject4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProject4App object

CProject4App theApp;


// CProject4App initialization

BOOL CProject4App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
