#include "shuffleKeyPad.h"

shuffleKeyPad::shuffleKeyPad(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1920, 1080);

    initializeValue(this->width(), this->height());
    drawLayout(this->width(), this->height());
}

shuffleKeyPad::~shuffleKeyPad()
{
    if (_vecBtnPos.size() != 0)
        _vecBtnPos.clear();
}

void shuffleKeyPad::initializeValue(int nWidth, int nHeight)
{

    enum CALLPOS
    {
        BTN_WIDTH = 0, 		// 버튼 너비 : Width * 0.1
        BTN_HEIGHT,		    // 버튼 높이 : Height * 0.1
        BTN_LEFT_LV0 = 2,	// (1 4 7 *)	LEFT 위치	: Width * 0.05
        BTN_LEFT_LV1,	    // (2 5 8 0)	LEFT 위치
        BTN_LEFT_LV2,	    // (3 6 9 #)	LEFT 위치
        BTN_TOP_LV0,    	// (* 0 #)		TOP 위치	: Height * 0.75
        BTN_TOP_LV1,	    // (7 8 9)		TOP 위치	: Height * 0.60
        BTN_TOP_LV2,	    // (4 5 6)  	TOP 위치	: Height * 0.45
        BTN_TOP_LV3,	    // (1 2 3 + -)	TOP 위치	: Height * 0.30
    };

    _vecBtnPos.push_back(nWidth * 0.1);
    _vecBtnPos.push_back(nHeight * 0.1);

    _vecBtnPos.push_back(nWidth * 0.05);
    _vecBtnPos.push_back(nWidth * 0.25);
    _vecBtnPos.push_back(nWidth * 0.45);

    _vecBtnPos.push_back(nHeight * 0.75);
    _vecBtnPos.push_back(nHeight * 0.60);
    _vecBtnPos.push_back(nHeight * 0.45);
    _vecBtnPos.push_back(nHeight * 0.30);

    originKeyPad();

    _strInput = "";

}

void shuffleKeyPad::drawLayout(int nWidth, int nHeight)
{
    // suffle button
    _btnshuffle = new QPushButton("Shuffle", this);
    _btnshuffle->setGeometry(nWidth * 0.05, nHeight * 0.05, nWidth * 0.50, nHeight * 0.1);

    // input result
    _lbInput = new QLabel(this);
    _lbInput->setGeometry(nWidth * 0.05, nHeight * 0.15, nWidth * 0.50, nHeight * 0.1);
    //_lbInput->setText("12345");

    // 1,2,3
    _btnNumber[1] = new QPushButton("1", this);
    _btnNumber[2] = new QPushButton("2", this);
    _btnNumber[3] = new QPushButton("3", this);

    _btnNumber[1]->setGeometry(_rtNumber[1]);
    _btnNumber[2]->setGeometry(_rtNumber[2]);
    _btnNumber[3]->setGeometry(_rtNumber[3]);

    // 4,5,6
    _btnNumber[4] = new QPushButton("4", this);
    _btnNumber[5] = new QPushButton("5", this);
    _btnNumber[6] = new QPushButton("6", this);

    _btnNumber[4]->setGeometry(_rtNumber[4]);
    _btnNumber[5]->setGeometry(_rtNumber[5]);
    _btnNumber[6]->setGeometry(_rtNumber[6]);

    // 7,8,9
    _btnNumber[7] = new QPushButton("7", this);
    _btnNumber[8] = new QPushButton("8", this);
    _btnNumber[9] = new QPushButton("9", this);

    _btnNumber[7]->setGeometry(_rtNumber[7]);
    _btnNumber[8]->setGeometry(_rtNumber[8]);
    _btnNumber[9]->setGeometry(_rtNumber[9]);

    // *,0,#
    _btnNumber[10] = new QPushButton("*", this);
    _btnNumber[0] = new QPushButton("0", this);
    _btnNumber[11] = new QPushButton("#", this);

    _btnNumber[10]->setGeometry(_rtNumber[10]);
    _btnNumber[0]->setGeometry(_rtNumber[0]);
    _btnNumber[11]->setGeometry(_rtNumber[11]);

    connect(_btnNumber[0], &QPushButton::clicked, this, &shuffleKeyPad::click_00);
    connect(_btnNumber[1], &QPushButton::clicked, this, &shuffleKeyPad::click_01);
    connect(_btnNumber[2], &QPushButton::clicked, this, &shuffleKeyPad::click_02);
    connect(_btnNumber[3], &QPushButton::clicked, this, &shuffleKeyPad::click_03);
    connect(_btnNumber[4], &QPushButton::clicked, this, &shuffleKeyPad::click_04);
    connect(_btnNumber[5], &QPushButton::clicked, this, &shuffleKeyPad::click_05);
    connect(_btnNumber[6], &QPushButton::clicked, this, &shuffleKeyPad::click_06);
    connect(_btnNumber[7], &QPushButton::clicked, this, &shuffleKeyPad::click_07);
    connect(_btnNumber[8], &QPushButton::clicked, this, &shuffleKeyPad::click_08);
    connect(_btnNumber[9], &QPushButton::clicked, this, &shuffleKeyPad::click_09);
    connect(_btnNumber[10], &QPushButton::clicked, this, &shuffleKeyPad::click_star);
    connect(_btnNumber[11], &QPushButton::clicked, this, &shuffleKeyPad::click_sharp);
    connect(_btnshuffle, &QPushButton::clicked, this, &shuffleKeyPad::KeyPadshuffle);
}

void shuffleKeyPad::originKeyPad()
{
    _rtNumber[0].setLeft(_vecBtnPos[BTN_LEFT_LV1]);
    _rtNumber[0].setTop(_vecBtnPos[BTN_TOP_LV0]);
    _rtNumber[0].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[0].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[1].setLeft(_vecBtnPos[BTN_LEFT_LV0]);
    _rtNumber[1].setTop(_vecBtnPos[BTN_TOP_LV3]);
    _rtNumber[1].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[1].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[2].setLeft(_vecBtnPos[BTN_LEFT_LV1]);
    _rtNumber[2].setTop(_vecBtnPos[BTN_TOP_LV3]);
    _rtNumber[2].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[2].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[3].setLeft(_vecBtnPos[BTN_LEFT_LV2]);
    _rtNumber[3].setTop(_vecBtnPos[BTN_TOP_LV3]);
    _rtNumber[3].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[3].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[4].setLeft(_vecBtnPos[BTN_LEFT_LV0]);
    _rtNumber[4].setTop(_vecBtnPos[BTN_TOP_LV2]);
    _rtNumber[4].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[4].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[5].setLeft(_vecBtnPos[BTN_LEFT_LV1]);
    _rtNumber[5].setTop(_vecBtnPos[BTN_TOP_LV2]);
    _rtNumber[5].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[5].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[6].setLeft(_vecBtnPos[BTN_LEFT_LV2]);
    _rtNumber[6].setTop(_vecBtnPos[BTN_TOP_LV2]);
    _rtNumber[6].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[6].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[7].setLeft(_vecBtnPos[BTN_LEFT_LV0]);
    _rtNumber[7].setTop(_vecBtnPos[BTN_TOP_LV1]);
    _rtNumber[7].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[7].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[8].setLeft(_vecBtnPos[BTN_LEFT_LV1]);
    _rtNumber[8].setTop(_vecBtnPos[BTN_TOP_LV1]);
    _rtNumber[8].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[8].setHeight(_vecBtnPos[BTN_HEIGHT]);

    _rtNumber[9].setLeft(_vecBtnPos[BTN_LEFT_LV2]);
    _rtNumber[9].setTop(_vecBtnPos[BTN_TOP_LV1]);
    _rtNumber[9].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[9].setHeight(_vecBtnPos[BTN_HEIGHT]);

    //*
    _rtNumber[10].setLeft(_vecBtnPos[BTN_LEFT_LV0]);
    _rtNumber[10].setTop(_vecBtnPos[BTN_TOP_LV0]);
    _rtNumber[10].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[10].setHeight(_vecBtnPos[BTN_HEIGHT]);

    //#
    _rtNumber[11].setLeft(_vecBtnPos[BTN_LEFT_LV2]);
    _rtNumber[11].setTop(_vecBtnPos[BTN_TOP_LV0]);
    _rtNumber[11].setWidth(_vecBtnPos[BTN_WIDTH]);
    _rtNumber[11].setHeight(_vecBtnPos[BTN_HEIGHT]);
}

void shuffleKeyPad::KeyPadshuffle()
{
    // 0 ~ 11까지... 10 = '*' 11 = '#'으로 간주
    int nTarget[NUMBER_AMOUNT] = { 0,1,2,3,4,5,6,7,8,9,10,11 };    
    int nTime = 0;
    int nRand, nTmp = -1;
    //QRect rtTmp;

    for (nTime = 0; nTime < 12; nTime++) // 섞기
    {
        nRand = rand() % 12;

        nTmp = nTarget[nTime];
        nTarget[nTime] = nTarget[nRand];
        nTarget[nRand] = nTmp;
    }

    for (nTime = 0; nTime < 12; nTime++) // 섞은 결과 보여주기
    {
        _btnNumber[nTarget[nTime]]->setGeometry(_rtNumber[nTime]);
        //_btnNumber[nTime]->setGeometry(_rtNumber[nTime]);
    }
    int nn = 50;
    nn = 70;
}

void shuffleKeyPad::click_00()
{
    _strInput += "0";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_01()
{
    _strInput += "1";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_02()
{
    _strInput += "2";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_03()
{
    _strInput += "3";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_04()
{
    _strInput += "4";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_05()
{
    _strInput += "5";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_06()
{
    _strInput += "6";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_07()
{
    _strInput += "7";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_08()
{
    _strInput += "8";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_09()
{
    _strInput += "9";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_star()
{
    _strInput += "*";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}

void shuffleKeyPad::click_sharp()
{
    _strInput += "#";
    _lbInput->setText(_strInput);
    KeyPadshuffle();
}