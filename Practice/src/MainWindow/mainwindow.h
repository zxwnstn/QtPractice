#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

private slots:
	void OnClick();
	void thread();
	void Ex8();
	void Ex9();
	void Ex10();
	void Ex13();
	void Ex15();
	void Ex19();
	void Ex20();
	void Ex21();
	void Ex23();
	void Ex24();
	void Ex25();
	void Ex26();

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
	QPushButton* ex23pushButton;
	QPushButton* ex24pushButton;
	QPushButton* ex25pushButton;
	QPushButton* ex26pushButton;
	QPushButton* ex27pushButton;
	QPushButton* exthreadpushButton;
};