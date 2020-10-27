#include "pch.h"

#include "MainWindow/mainwindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QFontDatabase::addApplicationFont("C:\\Dev\\QtPractice\\Practice\\fonts\\BMJUA_ttf.ttf");
	QFontDatabase::addApplicationFont(":myfile/fonts/segoeui.ttf");
	QFontDatabase::addApplicationFont(":myfile/fonts/segoeuib.ttf");
	app.setFont(QFont("Segoe UI"));

	MainWindow w;

	w.show();
	return app.exec();
}