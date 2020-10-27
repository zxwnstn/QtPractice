#pragma once

class MyFirstThread : public QThread
{
public:
	MyFirstThread(const QString& name);

	void run() override;

public:
	QString name;

};