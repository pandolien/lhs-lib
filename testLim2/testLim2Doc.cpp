// testLim2Doc.cpp : implementation of the CTestLim2Doc class
//

#include "stdafx.h"
#include "testLim2.h"

#include "testLim2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestLim2Doc

IMPLEMENT_DYNCREATE(CTestLim2Doc, CDocument)

BEGIN_MESSAGE_MAP(CTestLim2Doc, CDocument)
	//{{AFX_MSG_MAP(CTestLim2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLim2Doc construction/destruction

CTestLim2Doc::CTestLim2Doc()
{
	// TODO: add one-time construction code here

}

CTestLim2Doc::~CTestLim2Doc()
{
}

BOOL CTestLim2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestLim2Doc serialization

void CTestLim2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestLim2Doc diagnostics

#ifdef _DEBUG
void CTestLim2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestLim2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestLim2Doc commands
