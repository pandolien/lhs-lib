// testLim2View.cpp : implementation of the CTestLim2View class
//

#include "stdafx.h"
#include "testLim2.h"

#include "testLim2Doc.h"
#include "testLim2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View

IMPLEMENT_DYNCREATE(CTestLim2View, CView)

BEGIN_MESSAGE_MAP(CTestLim2View, CView)
	//{{AFX_MSG_MAP(CTestLim2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View construction/destruction

CTestLim2View::CTestLim2View()
{
	// TODO: add construction code here
	m_A.PAAALL2();
	m_A.PAASAVE();	
	//m_A.ALLMean();
	//m_A.MeanSave();
}

CTestLim2View::~CTestLim2View()
{
}

BOOL CTestLim2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View drawing

void CTestLim2View::OnDraw(CDC* pDC)
{
	CTestLim2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View printing

BOOL CTestLim2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestLim2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestLim2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View diagnostics

#ifdef _DEBUG
void CTestLim2View::AssertValid() const
{
	CView::AssertValid();
}

void CTestLim2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestLim2Doc* CTestLim2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestLim2Doc)));
	return (CTestLim2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestLim2View message handlers
#include "uOutlier.h"
#include "uMatrix.h"
#include "math.h"
void CTestLim2View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	uMatrix m_AMatrix;
	int i,n = 0;
	float f[] = {-100.0,100.0,-100.0,100.0,-100.0,100.0};
	gr.Init(this,CRect(0,0,400,400));
	gr.Add(m_A.d_PAA.Search(0));
	//gr.Add(m_A.d_Rode.Search(0),RGB(0,0,255));
	gr.Axis(f);
	gr.show();
	// TODO: Add your specialized code here and/or call the base class
	
}
