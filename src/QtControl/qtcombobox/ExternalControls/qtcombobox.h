#ifndef QTCOMBOBOX_H
#define QTCOMBOBOX_H

#include <QtWidgets/QMainWindow>
#include "ui_qtcombobox.h"

class HtmlComboBox;
class qtcombobox : public QMainWindow
{
	Q_OBJECT

public:
	qtcombobox(QWidget *parent = 0);
	~qtcombobox();

private slots:
	void currentTextChanged6(const QString& str);
	void idComboBoxItemChanged(qint64 id, const QString& str);
	void htmlItemPressed(int index);
	void modalPop();
	void testDialog();
private:
	Ui::qtcomboboxClass ui;
	HtmlComboBox* box;
};

#endif // QTCOMBOBOX_H