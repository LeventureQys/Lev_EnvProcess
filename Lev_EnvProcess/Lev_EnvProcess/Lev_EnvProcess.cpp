#include "Lev_EnvProcess.h"
static	BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	Q_UNUSED(lParam);

	char windowTitle[256];
	GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));
	if (strlen(windowTitle) > 0) {
		QString title = QString::fromLocal8Bit(windowTitle);
		EnvProcess::Singleton()->WindowTitles.append(title);
	}
	return TRUE;
}

EnvProcess* EnvProcess::Singleton() {
	static QMutex mutext;
	static QSharedPointer<EnvProcess> inst;
	if (Q_UNLIKELY(!inst)) {
		if (!inst) {
			inst.reset(new EnvProcess());
		}
	}
	return inst.data();
}

QList<QString> EnvProcess::GetWindowTitles()
{
	//QtConcurrent::run([=]() {
	this->InitWindowTitles();
	//});

	return EnvProcess::WindowTitles;
}
void EnvProcess::InitWindowTitles()
{
	this->WindowTitles.clear();
	QTextCodec* codec = QTextCodec::codecForName("GB2312");
	EnumWindows(&EnumWindowsProc, reinterpret_cast<LPARAM>(codec));
}
;