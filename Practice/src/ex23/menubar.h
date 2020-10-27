#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Ex23; }
QT_END_NAMESPACE

class menubar : public QMainWindow
{
	Q_OBJECT

public:
	menubar(QWidget *parent = nullptr);
	~menubar();

private slots:
	void onOpen();

private:
	Ui::Ex23* ui;
};