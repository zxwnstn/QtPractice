#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QPropertyAnimation>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>
#include <QPainter>
#include <QDesktopWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

private slots:
	void OnClick();
	void Ex8();
	void Ex9();
	void Ex10();
	void Ex13();
	void Ex15();
	void Ex19();
	void Ex20();
	void Ex21();

public:
	void NoneSlotsListener();

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	
	QPushButton* ex_ex1_pushButton;


	QPushButton* ex8pushButton;
	QPushButton* ex9pushButton;
	QPushButton* ex10pushButton;
	QPushButton* ex13pushButton;
	QPushButton* ex15pushButton;
	QPushButton* ex19pushButton;
	QPushButton* ex20pushButton;
	QPushButton* ex21pushButton;
};