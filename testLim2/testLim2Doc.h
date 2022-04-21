// testLim2Doc.h : interface of the CTestLim2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTLIM2DOC_H__B0B267C4_1355_4C4D_9876_7BAE7E8ECA34__INCLUDED_)
#define AFX_TESTLIM2DOC_H__B0B267C4_1355_4C4D_9876_7BAE7E8ECA34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestLim2Doc : public CDocument
{
protected: // create from serialization only
	CTestLim2Doc();
	DECLARE_DYNCREATE(CTestLim2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLim2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestLim2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestLim2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLIM2DOC_H__B0B267C4_1355_4C4D_9876_7BAE7E8ECA34__INCLUDED_)
