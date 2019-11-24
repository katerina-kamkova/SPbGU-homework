#pragma once

#define WM_AVXEDIT_CHANGE WM_USER+1

#include "afxwin.h"
class CAvxEdit :
	public CEdit
{
protected:
	// ���������, ��� �� ������� �������� ������������������ ���������, � ���� ��,
	// ���������� ����� ������. ���� ���, ���������� 0.
	static int test(TCHAR *txt);
	// ��������� ������ txt � __m256i. �������� ������������ txt �� ������������
	static __m256i txt2avx(TCHAR *txt);
	// ��������� __m256i � ��������� ������
	static TCHAR* avx2txt(TCHAR* txt, __m256i avx);
	CBrush m_Brush;
	COLORREF m_Color;
public:
	CAvxEdit();
	~CAvxEdit();
	// ���������� �������� ���������� ����
	void SetAvxValue(__m256i a);
	// ��������� �������� ���������� ����. ���� ���� ������������
	//  �� � ���������� ����������������� �������, ������������ 000...0
	__m256i GetAvxValue();
	// ��������� ������������ ���������� ����, �.�. �������� �� ��� �������
	//  16-������ ���� ������ 64 �������
	BOOL TestAvxValue();

	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnEnChange();
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};



// CCreateEasyStorageDlg dialog

class CCreateEasyStorageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateEasyStorageDlg)

public:
	CCreateEasyStorageDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCreateEasyStorageDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOGCREATE_EASY_STORAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
private:
	CButton m_btnOK;	
	CAvxEdit m_D0_Edit;
	CAvxEdit m_D1_Edit;
	CAvxEdit m_D2_Edit;
	CAvxEdit m_D3_Edit;
	CAvxEdit m_D4_Edit;
	CButton m_D0_btn;
	CButton m_D1_btn;
	CButton m_D2_btn;
	CButton m_D3_btn;
	CButton m_D4_btn;
	__m256i m_D[5];
	int m_Destroyed[2];
protected:
	afx_msg LRESULT OnAvxeditChange(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedCheck0();
public:
	CButton* GetButtonPtr(int no);
	__int64* GetStripe(__int64* Stripe, int* Destroyed);
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedOk();
};
