#include "pch.h"

#include "menubar.h"

#include "ui_menubar.h"

menubar::menubar(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Ex23)
{
	ui->setupUi(this);

	QObject::connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(onOpen()));

	connect(ui->actionOpen, &QAction::triggered, [this]() {
		QMessageBox::information(this, "hello", "wolrld");
	});
}

void menubar::onOpen()
{
	QMessageBox::information(this, "hello", "sxd");
}

menubar::~menubar()
{

}

