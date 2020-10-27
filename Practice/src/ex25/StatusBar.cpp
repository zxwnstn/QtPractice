#include "pch.h"

#include "StatusBar.h"
#include "ui_StatusBar.h"


StatusBar::StatusBar(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::StatusBar)
{
	ui->setupUi(this);
	//setWindowFlag(Qt::FramelessWindowHint);
	connect(ui->actionDoSomething_2, SIGNAL(triggered()), SLOT(DoSomething()));

	QFont font("BM JUA");

	this->setFont(font);

	ui->actionDoSomething_2->setFont(font);

	label = new QLabel;
	label->setFont(font);
	label->setText(QString::fromStdWString(L"¼½½º"));
	progressBar = new QProgressBar;

	progressBar->setValue(0);
	progressBar->setTextVisible(false);
	progressBar->setFont(font);

	ui->statusbar->addPermanentWidget(progressBar, 2);
	ui->statusbar->addPermanentWidget(label, 1);
}

void StatusBar::DoSomething()
{
	ui->statusbar->showMessage("hello");
	auto v = progressBar->value();
	if (v != 100)
	{
		v+=10;
	}
	else
	{
		v = 0;
	}
	progressBar->setValue(v);
}

StatusBar::~StatusBar()
{
	delete ui;
	delete label;
	delete progressBar;
}
