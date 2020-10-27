#include "pch.h"

#include "ProgressBar.h"
#include "ui_Progressbar.h"

ProgressBar::ProgressBar(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::ex24)
{
	ui->setupUi(this);
	ui->progressBar->setValue(ui->horizontalScrollBar->value());
}

ProgressBar::~ProgressBar()
{
	delete ui;
}