#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class ex24; }
QT_END_NAMESPACE

class ProgressBar : public QWidget
{
	Q_OBJECT

public:
	ProgressBar(QWidget* parent = nullptr);
	~ProgressBar();

private:
	Ui::ex24* ui;

};