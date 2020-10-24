#include "pch.h"

#include "MyFirstWidget.h"
#include "MySecondWidget.h"

MySecondWidget::MySecondWidget(QWidget *parent)
	: QWidget(parent)
{
	setupUi();
}


MySecondWidget::~MySecondWidget()
{
	
	

}

void MySecondWidget::setupUi()
{
	if (objectName().isEmpty())
		setObjectName(QString::fromUtf8("Second"));
	setGeometry(QRect(100, 100, 300, 500));

	pushButton = new QPushButton(this);
	pushButton->setObjectName(QString::fromUtf8("pushButton"));
	pushButton->setGeometry(QRect(100, 100, 150, 250));

	setWindowTitle(QCoreApplication::translate("Second", "Second", nullptr));
	pushButton->setText(QCoreApplication::translate("Second", "PushButton", nullptr));
}
