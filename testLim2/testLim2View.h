// testLim2View.h : interface of the CTestLim2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTLIM2VIEW_H__E8B223B3_216C_46E0_AC15_EC78312B679E__INCLUDED_)
#define AFX_TESTLIM2VIEW_H__E8B223B3_216C_46E0_AC15_EC78312B679E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CGraph3Dw.h"
#include "uOutlier.h"
class CTestLim2View : public CView
{
protected: // create from serialization only
	CTestLim2View();
	DECLARE_DYNCREATE(CTestLim2View)

// Attributes
public:
	CTestLim2Doc* GetDocument();
	lGraph3Dw gr;
	uOutlier m_A;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLim2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestLim2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestLim2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testLim2View.cpp
inline CTestLim2Doc* CTestLim2View::GetDocument()
   { return (CTestLim2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLIM2VIEW_H__E8B223B3_216C_46E0_AC15_EC78312B679E__INCLUDED_)
