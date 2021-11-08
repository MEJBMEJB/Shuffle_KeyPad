#pragma once

#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "ui_shuffleKeyPad.h"

#define NUMBER_AMOUNT 12

enum CALLPOS
{
    BTN_WIDTH = 0, 		// ��ư �ʺ� : Width * 0.1
    BTN_HEIGHT,		    // ��ư ���� : Height * 0.1
    BTN_LEFT_LV0 = 2,	// (1 4 7 *)	LEFT ��ġ	: Width * 0.05
    BTN_LEFT_LV1,	    // (2 5 8 0)	LEFT ��ġ
    BTN_LEFT_LV2,	    // (3 6 9 #)	LEFT ��ġ
    BTN_TOP_LV0,    	// (* 0 #)		TOP ��ġ	: Height * 0.75
    BTN_TOP_LV1,	    // (7 8 9)		TOP ��ġ	: Height * 0.60
    BTN_TOP_LV2,	    // (4 5 6)  	TOP ��ġ	: Height * 0.45
    BTN_TOP_LV3,	    // (1 2 3 + -)	TOP ��ġ	: Height * 0.30
};

class shuffleKeyPad : public QMainWindow
{
    Q_OBJECT

public:
    shuffleKeyPad(QWidget *parent = Q_NULLPTR);
    ~shuffleKeyPad();

private slots:
    void click_00();
    void click_01();
    void click_02();
    void click_03();
    void click_04();
    void click_05();
    void click_06();
    void click_07();
    void click_08();
    void click_09();
    void click_star();
    void click_sharp();


private:
    void initializeValue(int nWidth, int nHeight);
    void drawLayout(int nWidth, int nHeight);
    void KeyPadshuffle();
    void originKeyPad(); //ó�� ���·� �ǵ�����

private:
    QPushButton* _btnNumber[NUMBER_AMOUNT];
    QPushButton* _btnshuffle;
    QRect _rtNumber[NUMBER_AMOUNT];
    QLabel* _lbInput;
    QString _strInput;

    std::vector<int> _vecBtnPos;
};
