#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"


class QtWidgetsApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	explicit QtWidgetsApplication1(QWidget* parent = nullptr);
signals:;	// �Զ����ź�
public slots:
	void start();   // �Զ���ۺ�������.cpp��ʵ��
	void restart(); 
private:
	Ui::QtWidgetsApplication1Class ui;
};


