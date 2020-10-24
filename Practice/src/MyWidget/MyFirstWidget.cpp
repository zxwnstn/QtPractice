#include "pch.h"

#include "MyFirstWidget.h"

#include "ui_MyFirstWidget.h"


MyFirstWidget::MyFirstWidget(QWidget * parent, int x, int y)
	: QWidget(parent)
	, ui(new Ui::Form)
	, myX(x + 20)
	, myY(y + 20)
{
	ui->setupUi(this);

	//setGeometry(myX, myY, 400, 300);

	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(mOnClick()));
	QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(mOnClick2()));
}	

void MyFirstWidget::mOnClick()
{
	auto text = ui->lineEdit->text();
	std::cout << text.toStdString();
	close();
}

void MyFirstWidget::mOnClick2()
{
	close();
}

MyFirstWidget::~MyFirstWidget()
{
}
