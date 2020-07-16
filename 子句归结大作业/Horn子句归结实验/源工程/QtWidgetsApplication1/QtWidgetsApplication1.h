#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"


class QtWidgetsApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	explicit QtWidgetsApplication1(QWidget* parent = nullptr);
signals:;	// 自定义信号
public slots:
	void start();   // 自定义槽函数，在.cpp中实现
	void restart(); 
private:
	Ui::QtWidgetsApplication1Class ui;
};


