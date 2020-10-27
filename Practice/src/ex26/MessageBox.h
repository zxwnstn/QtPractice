#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class MessageBox; }
QT_END_NAMESPACE

class MessageBox : public QWidget
{
	Q_OBJECT
public:
	MessageBox(QWidget* parent = nullptr);
	~MessageBox();

private slots:
	void Info();
	void Custom();
	void Question();
	void Warning();


private:
	Ui::MessageBox* ui;
};