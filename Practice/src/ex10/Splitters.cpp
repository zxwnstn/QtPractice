#include "pch.h"

#include "Splitters.h"

#include "ui_Splitters.h"

Splitter::Splitter(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Splitters)
{
	ui->setupUi(this);
}

Splitter::~Splitter()
{

}

