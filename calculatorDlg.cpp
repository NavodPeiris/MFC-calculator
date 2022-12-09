
// calculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg dialog



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT_ABOUT, &CcalculatorDlg::OnAboutAbout)
//	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON15, &CcalculatorDlg::OnClick1)
ON_BN_CLICKED(IDC_BUTTON16, &CcalculatorDlg::OnClick2)
ON_BN_CLICKED(IDC_BUTTON17, &CcalculatorDlg::OnClick3)
ON_BN_CLICKED(IDC_BUTTON12, &CcalculatorDlg::OnClick4)
ON_BN_CLICKED(IDC_BUTTON13, &CcalculatorDlg::OnClick5)
ON_BN_CLICKED(IDC_BUTTON14, &CcalculatorDlg::OnClick6)
ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnClick7)
ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorDlg::OnClick8)
ON_BN_CLICKED(IDC_BUTTON11, &CcalculatorDlg::OnClick9)
ON_BN_CLICKED(IDC_BUTTON18, &CcalculatorDlg::OnClick0)
ON_BN_CLICKED(IDC_BUTTON20, &CcalculatorDlg::OnClickDEL)
ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnClickAdd)
ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnClickSubtract)
ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnClickMultiply)
ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnClickDivide)
ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnClickRemainder)
ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnClickPower)
ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnClickCLR)
ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnClickEQUAL)
ON_BN_CLICKED(IDC_BUTTON19, &CcalculatorDlg::OnClickDot)
END_MESSAGE_MAP()


// CcalculatorDlg message handlers

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	menu.LoadMenuW(IDR_MENU1);
	SetMenu(&menu);

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	//  when the application's main window is not a dialog
	//SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnAboutAbout()
{
	// TODO: Add your command handler code here
	MessageBox(_T("1. H.R.N.T Peiris 20/ENG/097\n2. Y.H.G Punchihewa 20/ENG/194\n3. T.D.D Samaranayake 20/ENG/123\n4. R.M.M.D Rajapaksha 20/ENG/195"), _T("Team Members"));
}

CString displayString = _T("");       //string for display
CString strvalue1 = _T("");          //value1 as a CString
CString strvalue2 = _T("");          //value2 as a CString
CString strtotal = _T("");           //total as a CString

float total = 0, value1, value2;   //total, value1, value2   value1 - operand1  value2 - operand2 total - final result
CString state = _T("");             //operation 

void calc() {
	if (state == "+") {
		total = total +  value2;
	}
	else if (state == "-") {
		total = total - value2;
	}
	else if (state == "*") {
		total = total * value2;
	}
	else if (state == "/") {
		total = total / value2;
	}
	else if (state == "%") {
		total = int(total) % int(value2);
	}
	else if (state == "^") {
		total = pow(total, value2);
	}
}


void CcalculatorDlg::OnClick1()
{
	if (total == 0) {
		displayString += _T("1");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("1");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick2()
{
	if (total == 0) {
		displayString += _T("2");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("2");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick3()
{
	if (total == 0) {
		displayString += _T("3");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("3");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}

void CcalculatorDlg::OnClick4()
{
	if (total == 0) {
		displayString += _T("4");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("4");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick5()
{
	if (total == 0) {
		displayString += _T("5");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("5");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick6()
{
	if (total == 0) {
		displayString += _T("6");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("6");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick7()
{
	if (total == 0) {
		displayString += _T("7");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("7");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick8()
{
	if (total == 0) {
		displayString += _T("8");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}
		
	}
	else {
		displayString += _T("8");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick9()
{
	if (total == 0) {
		displayString += _T("9");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("9");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClick0()
{
	if (total == 0) {
		displayString += _T("0");
		if (state == "-") {
			SetDlgItemText(IDC_EDIT1, _T("-") + displayString);
		}
		else {
			SetDlgItemText(IDC_EDIT1, displayString);
		}

	}
	else {
		displayString += _T("0");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
}


void CcalculatorDlg::OnClickDot()
{
	if (state == "") {
		displayString += _T(".");
		SetDlgItemText(IDC_EDIT1, displayString);
	}
	else {
		displayString += _T(".");
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
	
}


void CcalculatorDlg::OnClickDEL()
{
	if (state == "") {
		displayString.Delete(displayString.GetLength() - 1, 1);
		SetDlgItemText(IDC_EDIT1, displayString);
	}
	else {
		displayString.Delete(displayString.GetLength() - 1, 1);
		SetDlgItemText(IDC_EDIT1, strvalue1 + state + displayString);
	}
	
}


void CcalculatorDlg::OnClickAdd()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("+"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "+";
		displayString.Empty();
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickAdd();
	}
}


void CcalculatorDlg::OnClickSubtract()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("-"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "-";
		displayString.Empty();
	}
	else if (state == "*" || state == "/" || state == "%" || state == "^") {
		strvalue1.Format(_T("%.3f"), value1);
		state += "-";
		SetDlgItemText(IDC_EDIT1, strvalue1 + state);
		
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickSubtract();
	}
}


void CcalculatorDlg::OnClickMultiply()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("*"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "*";
		displayString.Empty();
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickMultiply();
	}
	
}


void CcalculatorDlg::OnClickDivide()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("/"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "/";
		displayString.Empty();
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickDivide();
	}
}


void CcalculatorDlg::OnClickRemainder()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("%"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "%";
		displayString.Empty();
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickRemainder();
	}
}


void CcalculatorDlg::OnClickPower()
{
	if (state == "") {
		SetDlgItemText(IDC_EDIT1, displayString + _T("^"));
		value1 = _tstof((LPCTSTR)displayString);
		strvalue1.Format(_T("%.3f"), value1);
		total = total + value1;
		state = "^";
		displayString.Empty();
	}
	else {
		CcalculatorDlg::OnClickEQUAL();
		CcalculatorDlg::OnClickPower();
	}
}


void CcalculatorDlg::OnClickCLR()
{
	displayString.Empty();
	strvalue1.Empty();
	strvalue2.Empty();
	state.Empty();
	total = 0;
	strtotal.Empty();
	SetDlgItemText(IDC_EDIT1, displayString);
}

void CcalculatorDlg::OnClickEQUAL()
{

	if (state == "*-" || state == "/-" || state == "%-" || state == "^-") {
		state.Delete(state.GetLength() - 1, 1);
		displayString = _T("-") + displayString;
		value2 = _tstof((LPCTSTR)displayString);
		if (state == "/" || state == "%") {
			if (value2 == 0) {
				MessageBox(_T("can't divide by zero"), _T("Error: Zero Division"));
				CcalculatorDlg::OnClickCLR();
				return;
			}
		}
		calc();
		strtotal.Format(_T("%.3f"), total);
		SetDlgItemText(IDC_EDIT1, strtotal);
		total = 0;
		displayString = strtotal;
		state.Empty();
	}
	else {
		value2 = _tstof((LPCTSTR)displayString);
		if (state == "/" || state == "%") {
			if (value2 == 0) {
				MessageBox(_T("can't divide by zero"), _T("Error: Zero Division"));
				CcalculatorDlg::OnClickCLR();
				return;
			}
		}
		calc();
		strtotal.Format(_T("%.3f"), total);
		SetDlgItemText(IDC_EDIT1, strtotal);
		total = 0;
		displayString = strtotal;
		state.Empty();
	}
}


