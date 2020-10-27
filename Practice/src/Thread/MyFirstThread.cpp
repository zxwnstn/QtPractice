#include "pch.h"

#include "MyFirstThread.h"

MyFirstThread::MyFirstThread(const QString& name)
	: name(name)
{
}

void MyFirstThread::run()
{
	for (int i = 0; i < 1000; ++i)
	{
		qDebug() << name << " : " << i;
	}
	this->exit();
}
