#pragma once
#include "QssString.h"
#include <string>
#include <QColor>

class QShowEvent;
class QWidget;
template <class QBase>
class ControlShow : public QBase
{
public:
	/** 重画
	*/
	virtual void repaint();

protected:
	/** 构造函数
	@param [in] parent 父窗口指针
	*/
	ControlShow(QWidget* parent = nullptr);

	/** 析构函数
	*/
	virtual ~ControlShow();

protected:
	/** 初始化
	@param [in] className 类名
	@param [in] itemName 节点名
	*/
	void init(const std::wstring& className, const std::wstring& itemName);

private:
	virtual void showEvent(QShowEvent* eve);

public:
	//style字符串管理对象
	QssString m_controlStyle;
	//类名字符串
	std::wstring m_className;
	//节点名字符串
	std::wstring m_itemName;
};

#include "ControlShow.inl"
