#include "pch.h"
#include "MessageBox.h"
#include "ui_MessageBox.h"

MessageBox::MessageBox(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MessageBox)
{
	ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), SLOT(Info()));
	connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(Question()));
	connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(Warning()));
	connect(ui->pushButton_4, SIGNAL(clicked()), SLOT(Custom()));
}

void MessageBox::Info()
{
	QMessageBox::information(this, "title here", "text here");
}

void MessageBox::Question()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::information(this, "title here", "Do you like sex?",
		QMessageBox::Yes, QMessageBox::No);

	if (reply == QMessageBox::Yes)
	{
		reply = QMessageBox::information(this, "title here", "You are man");
	}
	else
	{
		reply = QMessageBox::information(this, "title here", "You are simyoung");
	}

}


void MessageBox::Warning()
{
	QMessageBox::warning(this, "Warn!!", "your computer is in sex virus!");
}

void MessageBox::Custom()
{
	auto reply = QMessageBox::question(this, "title", "text",
		QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);

	switch (reply)
	{
	case QMessageBox::Yes:
		QMessageBox::information(this, "yes", "yes");
		break;
	case QMessageBox::YesToAll:
		QMessageBox::information(this, "yes", "yes all");
		break;
	case QMessageBox::No:
		QMessageBox::information(this, "yes", "no");
		break;
	case QMessageBox::NoToAll:
		QMessageBox::information(this, "yes", "no all");
		break;
	}
}

MessageBox::~MessageBox()
{
	delete ui;
}


