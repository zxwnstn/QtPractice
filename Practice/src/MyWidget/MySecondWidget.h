#pragma once


class MySecondWidget : public QWidget
{
	Q_OBJECT

public:
	MySecondWidget(QWidget *parent = nullptr);
	~MySecondWidget();

private:
	void setupUi();

	QPushButton* pushButton;


};