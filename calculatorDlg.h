
// calculatorDlg.h : header file
//

#pragma once


// CcalculatorDlg dialog
class CcalculatorDlg : public CDialogEx
{
// Construction
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAboutAbout();
	CMenu menu;
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnClick1();
	afx_msg void OnClick2();
	afx_msg void OnClick3();
	afx_msg void OnClick4();
	afx_msg void OnClick5();
	afx_msg void OnClick6();
	afx_msg void OnClick7();
	afx_msg void OnClick8();
	afx_msg void OnClick9();
	afx_msg void OnClick0();
	afx_msg void OnClickDEL();
	afx_msg void OnClickAdd();
	afx_msg void OnClickSubtract();
	afx_msg void OnClickMultiply();
	afx_msg void OnClickDivide();
	afx_msg void OnClickRemainder();
	afx_msg void OnClickPower();
	afx_msg void OnClickCLR();
	afx_msg void OnClickEQUAL();
	afx_msg void OnClickDot();

};
