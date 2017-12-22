#pragma once
#include "QssString.h"
#include <string>
#include <QColor>

#define INIT(itemName) init(QString::fromStdString(CStringManager::Replace(typeid(*this).name(), "class ", "")).toStdWString(), itemName)

class QShowEvent;
class QWidget;
template <class QBase>
class ControlShow : public QBase
{
public:
	/** �ػ�
	*/
	virtual void repaint();

protected:
	/** ���캯��
	@param [in] parent ������ָ��
	*/
	ControlShow(QWidget* parent = nullptr);

	/** ��������
	*/
	virtual ~ControlShow();

protected:
	/** ��ʼ��
	@param [in] className ����
	@param [in] itemName �ڵ���
	*/
	bool init(const std::wstring& className, const std::wstring& itemName = L"");

private:
	virtual void showEvent(QShowEvent* eve);

public:
	//style�ַ�����������
	QssString m_controlStyle;
	//�����ַ���
	std::wstring m_className;
	//�ڵ����ַ���
	std::wstring m_itemName;
};

#include "ControlShow.inl"