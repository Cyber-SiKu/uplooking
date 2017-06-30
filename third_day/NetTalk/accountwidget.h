#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QDialog>

namespace Ui {
class AccountWidget;
}

class AccountWidget : public QDialog
{
	Q_OBJECT

public:
	explicit AccountWidget(QWidget *parent = 0);
	~AccountWidget();

private:
	Ui::AccountWidget *ui;
};

#endif // ACCOUNTWIDGET_H
