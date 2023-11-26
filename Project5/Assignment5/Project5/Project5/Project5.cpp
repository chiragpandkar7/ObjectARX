// Project5.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project5.h"

// Load the common Windows headers
#include <windows.h>
// Load the common AutoCAD headers
#include "arxHeaders.h"
#include "dbents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CProject5App :: makeLayer()
{
	// Open the Layer table for read
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbLayerTable* pLayerTable;
	pDb->getLayerTable(pLayerTable, AcDb::kForRead);
	// Check to see if the layer exists
	if (pLayerTable->has(_T("OBJ")) == false)
	{
		// Open the Layer table for write
		pLayerTable->upgradeOpen();
		// Create the new layer and assign it the name 'OBJ'
		AcDbLayerTableRecord* pLayerTableRecord =
			new AcDbLayerTableRecord();
		pLayerTableRecord->setName(_T("OBJ"));
		// Set the color of the layer to cyan
		AcCmColor color;
		color.setColorIndex(4);
		pLayerTableRecord->setColor(color);
		// Add the new layer to the Layer table
		pLayerTable->add(pLayerTableRecord);
		// Close the Layer table and record
		pLayerTable->close();
		pLayerTableRecord->close();
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
		acedRegCmds->addCommand(_T("AUCommands"), _T("MakeLayer"), _T("MakeLayer"), ACRX_CMD_MODAL, &CProject5App::makeLayer);
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

// CProject5App

BEGIN_MESSAGE_MAP(CProject5App, CWinApp)
END_MESSAGE_MAP()


// CProject5App construction

CProject5App::CProject5App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProject5App object

CProject5App theApp;


// CProject5App initialization

BOOL CProject5App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
