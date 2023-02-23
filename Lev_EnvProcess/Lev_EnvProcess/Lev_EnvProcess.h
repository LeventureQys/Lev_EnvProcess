#pragma once

#include "lev_envprocess_global.h"
#include "qt_windows.h"
#include "qlist.h"
#include "qsharedpointer.h"
#include "qmutex.h"
#include "qtextcodec.h"
class LEV_ENVPROCESS_EXPORT EnvProcess {

public:
	EnvProcess() {

	};
	~EnvProcess() {};
	QList<QString> WindowTitles;
	//�Ƚ���������Ȼ��GetWindowTitles
	static EnvProcess* EnvProcess::Singleton();

	QList<QString> GetWindowTitles();
private:

	void InitWindowTitles();

};