
// FundInvestDlg.h : 头文件
//

#pragma once
#include <string>
#include <map>
#include <vector>
#include "IntDateTime/IntDateTimeAPI.h"
#include "DataNeuron.h"
#include "CSystem/CSystemAPI.h"

#define FUND_NUM std::string("110022")

class CDrawDlg;
// CFundInvestDlg 对话框
class CFundInvestDlg : public CDialogEx
{
// 构造
public:
	CFundInvestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FundInvest_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

private:
	void LoadFund();
	DataNeuron* GetFirstNeuron(const std::string& fundName);
	DataNeuron* GetNeuron(const std::string& fundName, const std::string& time);
    DataNeuron* GetNeuron(const std::string& fundName, const IntDateTime& time);

private:
	std::string m_fundPath = CSystem::GetEnvironment("xueyelingshuang") + "data\\Fund\\";
	std::string m_fundName = FUND_NUM;
	bool m_isOpenBuy = true;
	bool m_isOpenSell = true;

	std::map<std::string, std::map<IntDateTime, DataNeuron>> m_mapDataNeuron;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();

	void Draw(const std::map<double,double>& mapData);

	CDrawDlg * drawDlg = NULL;
	afx_msg void OnBnClickedButton12();

    double DaysBidSell(int32_t lookDays,
                       const IntDateTime& beginTime,
					   const IntDateTime& endTime,
					   double bid,
					   double sell);
    afx_msg void OnBnClickedButton13();

    //always，highest，bid，sell
    std::vector<double> GetBidSellInfo(int32_t lookDays, const IntDateTime& time, int32_t days);
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
};
