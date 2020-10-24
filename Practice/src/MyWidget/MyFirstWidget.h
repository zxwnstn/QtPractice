#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class MyFirstWidget : public QWidget
{
	Q_OBJECT

private slots:
	void mOnClick();
	void mOnClick2();

public:
	MyFirstWidget(QWidget *parent, int x, int y);
	~MyFirstWidget();

private:
	Ui::Form* ui;
	int myX, myY;
};