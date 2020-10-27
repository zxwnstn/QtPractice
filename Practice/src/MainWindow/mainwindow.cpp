#include "pch.h"

#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "MyWidget/MyFirstWidget.h"
#include "MyWidget/MySecondWidget.h"
#include "ex10/Splitters.h"
#include "ex23/menubar.h"
#include "ex24/ProgressBar.h"
#include "ex25/StatusBar.h"
#include "ex26/MessageBox.h"
#include "Thread/MyFirstThread.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	QFont font1("BM JUA");
	QFont font2("Segoe UI");
	QFont font3("Segoe UI");

	ui->setupUi(this);
	//ui->pushButton->setText("6: layout buddies, tabs");
	ui->pushButton->setText(QString::fromStdWString(L"·¹ÀÌ¾Æ¿ô"));
	ui->pushButton->setGeometry(10, 100, 130, 100);
	ui->pushButton->setFont(font1);

	ex8pushButton = new QPushButton(ui->centralwidget);
	ex8pushButton->setText(QString("8: Ver Hor layout"));
	ex8pushButton->setGeometry(QRect(10, 200, 130, 100));
	ex8pushButton->setFont(font2);

	ex9pushButton = new QPushButton(ui->centralwidget);
	ex9pushButton->setText(QString("9: Grid Layout"));
	ex9pushButton->setGeometry(QRect(10, 300, 130, 100));
	ex9pushButton->setFont(font3);

	ex10pushButton = new QPushButton(ui->centralwidget);
	ex10pushButton->setText(QString("10: Splitters"));
	ex10pushButton->setGeometry(QRect(10, 400, 130, 100));

	ex13pushButton = new QPushButton(ui->centralwidget);
	ex13pushButton->setText(QString("13: qrc"));
	ex13pushButton->setGeometry(QRect(10, 500, 130, 100));

	ex15pushButton = new QPushButton(ui->centralwidget);
	ex15pushButton->setText(QString("15: pushbutton"));
	ex15pushButton->setGeometry(QRect(160, 100, 130, 100));

	ex19pushButton = new QPushButton(ui->centralwidget);
	ex19pushButton->setText(QString("19: comboBox"));
	ex19pushButton->setGeometry(QRect(160, 200, 130, 100));

	ex_ex1_pushButton = new QPushButton(ui->centralwidget);
	ex_ex1_pushButton->setText(QString("ex1: NoneSlotsListener"));
	ex_ex1_pushButton->setGeometry(QRect(160, 300, 130, 100));

	ex20pushButton = new QPushButton(ui->centralwidget);
	ex20pushButton->setText(QString("20: list widget"));
	ex20pushButton->setGeometry(QRect(160, 400, 130, 100));

	ex21pushButton = new QPushButton(ui->centralwidget);
	ex21pushButton->setText(QString("21: list widget"));
	ex21pushButton->setGeometry(QRect(160, 500, 130, 100));

	ex23pushButton = new QPushButton(ui->centralwidget);
	ex23pushButton->setText(QString("23: menubar action"));
	ex23pushButton->setGeometry(QRect(310, 100, 130, 100));

	ex24pushButton = new QPushButton(ui->centralwidget);
	ex24pushButton->setText(QString("24: progress bar"));
	ex24pushButton->setGeometry(QRect(310, 200, 130, 100));

	ex25pushButton = new QPushButton(ui->centralwidget);
	ex25pushButton->setText(QString("25: status bar"));
	ex25pushButton->setGeometry(QRect(310, 300, 130, 100));

	ex26pushButton = new QPushButton(ui->centralwidget);
	ex26pushButton->setText(QString("26: message box"));
	ex26pushButton->setGeometry(QRect(310, 400, 130, 100));

	exthreadpushButton = new QPushButton(ui->centralwidget);
	exthreadpushButton->setText(QString("thread"));
	exthreadpushButton->setGeometry(QRect(310, 500, 130, 100));

	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnClick()));
	QObject::connect(ex8pushButton, SIGNAL(clicked()), this, SLOT(Ex8()));
	QObject::connect(ex9pushButton, SIGNAL(clicked()), this, SLOT(Ex9()));
	QObject::connect(ex10pushButton, SIGNAL(clicked()), this, SLOT(Ex10()));
	QObject::connect(ex13pushButton, SIGNAL(clicked()), this, SLOT(Ex13()));
	QObject::connect(ex15pushButton, SIGNAL(clicked()), this, SLOT(Ex15()));
	QObject::connect(ex19pushButton, SIGNAL(clicked()), this, SLOT(Ex19()));
	QObject::connect(ex20pushButton, SIGNAL(clicked()), this, SLOT(Ex20()));
	QObject::connect(ex21pushButton, SIGNAL(clicked()), this, SLOT(Ex21()));
	QObject::connect(ex23pushButton, SIGNAL(clicked()), this, SLOT(Ex23()));
	QObject::connect(ex24pushButton, SIGNAL(clicked()), this, SLOT(Ex24()));
	QObject::connect(ex25pushButton, SIGNAL(clicked()), this, SLOT(Ex25()));
	QObject::connect(ex26pushButton, SIGNAL(clicked()), this, SLOT(Ex26()));
	QObject::connect(exthreadpushButton, SIGNAL(clicked()), this, SLOT(thread()));
	QObject::connect(ex_ex1_pushButton, &QPushButton::clicked, std::bind(&MainWindow::NoneSlotsListener, this));
}

MainWindow::~MainWindow()
{
	(new StatusBar)->show();
}


void MainWindow::NoneSlotsListener()
{
	QMessageBox::information(this, "Title here", "NoneSlotsListener");
}

void MainWindow::thread()
{
	auto thread1 = new MyFirstThread("high");
	auto thread2 = new MyFirstThread("normal");
	auto thread3 = new MyFirstThread("low");

	thread1->start(QThread::Priority::HighestPriority);
	thread2->start(QThread::Priority::NormalPriority);
	thread3->start(QThread::Priority::LowestPriority);
}

void MainWindow::Ex26()
{
	(new MessageBox)->show();
}


void MainWindow::Ex25()
{
	(new StatusBar)->show();
}

void MainWindow::Ex24()
{
	auto progress = new ProgressBar;
	progress->show();
}

void MainWindow::Ex23()
{
	auto menu = new menubar;
	menu->show();
}

void MainWindow::Ex21()
{
	auto widget = new QWidget;
	widget->setWindowTitle("Ex21");
	auto layout = new QVBoxLayout;
	widget->setGeometry(QRect(200, 200, 200, 200));

	widget->setLayout(layout);

	auto treeWidget = new QTreeWidget;
	treeWidget->setColumnCount(2);
	treeWidget->setColumnWidth(0, 90);
	treeWidget->setColumnWidth(1, 90);
	treeWidget->setHeaderLabels(QStringList() << "one" << "two");

	auto AddCild = [](QTreeWidgetItem* parent, const QString& first, const QString& second){
		auto item = new QTreeWidgetItem(parent);
		item->setText(0, first);
		item->setText(1, second);

		parent->addChild(item);
	};

	auto AddRoot = [&AddCild](QTreeWidget* tree, const QString& first, const QString& second) {
		auto item = new QTreeWidgetItem(tree);
		item->setText(0, first);
		item->setText(1, second);

		AddCild(item, "aa", "bb");
		AddCild(item, "cc", "dd");
	};

	AddRoot(treeWidget, "kang", "junsoo");
	AddRoot(treeWidget, "kim", "kiseop");
	AddRoot(treeWidget, "sex", "hagosipda");

	layout->addWidget(treeWidget);

	auto pushb = new QPushButton;
	pushb->setText("click me");
	layout->addWidget(pushb);

	QObject::connect(pushb, &QPushButton::clicked, [treeWidget]() {
		auto cur = treeWidget->currentItem();
		cur->setBackgroundColor(0, Qt::blue);
		cur->setBackgroundColor(1, Qt::red);
	});

	widget->show();
}

void MainWindow::Ex20()
{
	auto widget = new QWidget;
	auto layout = new QVBoxLayout;
	widget->setGeometry(QRect(200, 200, 100, 200));

	widget->setLayout(layout);

	auto listWidget = new QListWidget;
	layout->addWidget(listWidget);

	for (auto i = 0; i < 10; ++i)
	{
		listWidget->addItem(QString::number(i) + " item");
	}

	auto pushb = new QPushButton;
	pushb->setText("click me");
	layout->addWidget(pushb);

	QObject::connect(pushb, &QPushButton::clicked, widget, [listWidget]() {
		auto curitem = listWidget->currentItem();
		curitem->setText("Fuzzy Bunny");
		curitem->setTextColor(Qt::red);
		curitem->setBackgroundColor(Qt::black);
	});

	widget->show();
}

void MainWindow::Ex19()
{
	QWidget* widget = new QWidget;
	widget->setGeometry(QRect(300, 300, 200, 100));

	auto layout = new QVBoxLayout;
	widget->setLayout(layout);

	auto combo = new QComboBox(widget);
	for (int i = 0; i < 10; ++i)
	{
		combo->addItem(QString::number(i) + "item");
	}
	auto push = new QPushButton(widget);
	push->setText("click me");

	layout->addWidget(combo);
	layout->addWidget(push);

	QObject::connect(push, &QPushButton::clicked, this, 
		[widget, combo]() {
		QMessageBox::information(widget, "title", combo->currentText());
	});

	widget->show();
}



void MainWindow::Ex15()
{
	QMessageBox::information(this, "Title here", "hello world");
}

void MainWindow::Ex13()
{
	QFile mFile(":/myfile/text/asdf.txt");
	if (!mFile.open(QFile::ReadOnly | QFile::Text))
	{
		qDebug() << "Can't find qrc file";
		return;
	}

	QTextStream in(&mFile);
	while (!in.atEnd())
	{
		QString text = in.readLine();
		qDebug() << text;
	}
	std::cout << "eof\n";
}

void MainWindow::Ex10()
{
	auto split = new Splitter;
	split->show();
}

void MainWindow::Ex9()
{
	QWidget* widget = new QWidget;

	QGridLayout* gridLayout = new QGridLayout;
	widget->setLayout(gridLayout);

	QLabel* label1 = new QLabel("label1");
	QLineEdit* edit1 = new QLineEdit;
	QLabel* label2 = new QLabel("label2");
	QLineEdit* edit2 = new QLineEdit;

	QPushButton* pushButton = new QPushButton("botton");

	gridLayout->addWidget(label1, 0, 0);
	gridLayout->addWidget(edit1, 0, 1);
	gridLayout->addWidget(label2, 1, 0);
	gridLayout->addWidget(edit2, 1, 1);
	gridLayout->addWidget(pushButton, 2, 0, 1, 2);

	widget->show();

}

void MainWindow::Ex8()
{
	QWidget* widget = new QWidget();

	QPushButton* botton1 = new QPushButton(QString("Button1"));
	QPushButton* botton2 = new QPushButton(QString("Botton2"));
	QPushButton* botton3 = new QPushButton(QString("Button3"));

	//QHBoxLayout* layout = new QHBoxLayout(widget);
	QVBoxLayout* layout = new QVBoxLayout(widget);

	layout->addWidget(botton1);
	layout->addWidget(botton2);
	layout->addWidget(botton3);

	widget->show();
}

void MainWindow::OnClick()
{
	auto widget = new MyFirstWidget(nullptr, 500, 500);
	widget->show();
}

