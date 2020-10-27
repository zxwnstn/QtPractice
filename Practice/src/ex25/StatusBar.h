#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class StatusBar; }
QT_END_NAMESPACE

class StatusBar : public QMainWindow
{
	Q_OBJECT
public:
	StatusBar(QWidget* parent = nullptr);
	~StatusBar();

private slots:
	void DoSomething();

private:
	Ui::StatusBar* ui;

	QLabel* label;
	QProgressBar* progressBar;

};