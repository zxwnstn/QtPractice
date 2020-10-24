#pragma once


QT_BEGIN_NAMESPACE
namespace Ui { class Splitters; }
QT_END_NAMESPACE

class Splitter : public QWidget
{
	Q_OBJECT

public:
	Splitter(QWidget *parent = nullptr);
	~Splitter();

private:
	Ui::Splitters* ui;
};