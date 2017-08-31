// AddTime.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CalcTest.h"
#include "AddTime.h"
#include "afxdialogex.h"
#include "IntDateTime/IntDateTimeAPI.h"
#include "CCharset/CCharsetAPI.h"

// CAddTime �Ի���

IMPLEMENT_DYNAMIC(CAddTime, CDialogEx)

CAddTime::CAddTime(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddTime::IDD, pParent)
{

}

CAddTime::~CAddTime()
{
}

void CAddTime::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, m_time);
    DDX_Control(pDX, IDC_BUTTON1, m_ok);
}


BEGIN_MESSAGE_MAP(CAddTime, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &CAddTime::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddTime ��Ϣ��������


void CAddTime::OnBnClickedButton1()
{
    CString text;
    m_time.GetWindowText(text);
    if (text == _T("yangnan"))
    {
        EndDialog(98);
        return;
    }
    if (text == _T("Ĭ��"))
    {
        EndDialog(99);
        return;
    }
    if (text == _T("Ĭ�Ͽ۳�"))
    {
        EndDialog(97);
        return;
    }
    string strTime = CCharset::UnicodeToAnsi(text.GetBuffer());
    IntDateTime preTime(strTime);
    text.ReleaseBuffer();
    if (preTime.toString() != strTime)
    {
        AfxMessageBox(_T("��������"));
        return;
    }
    (*editTime) = preTime;
    EndDialog(100);
    // TODO:  �ڴ����ӿؼ�֪ͨ�����������
}

void CAddTime::SetEditTime(IntDateTime* editTime)
{
    this->editTime = editTime;
}

BOOL CAddTime::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  �ڴ����Ӷ���ĳ�ʼ��
    ::SetFocus(m_time.m_hWnd);
    return FALSE;  // return TRUE unless you set the focus to a control
    // �쳣:  OCX ����ҳӦ���� FALSE
}