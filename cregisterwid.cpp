#include "cregisterwid.h"

CRegisterWid::CRegisterWid(QWidget *parent)
    : QWidget{parent}
{
    m_label_Logo = new QLabel(this);
    m_label_Register = new QLabel(this);
    m_ledit_UserName = new QLineEdit(this);
    m_ledit_PassWord = new QLineEdit(this);
    m_ledit_PhoneNum = new QLineEdit(this);
    m_ledit_CheckNum = new QLineEdit(this);
    m_pbtn_GetCheckNum = new QPushButton(this);
    m_pbtn_Register = new QPushButton(this);
    m_pbtn_Login = new QPushButton(this);
    m_pbtn_MainWid = new QPushButton(this);
    m_wid_RegisterWid = new QWidget(this);
    m_hlay_Main = new QHBoxLayout();
    initRegisterWid();
    connectSignalSlot();
}

CRegisterWid::~CRegisterWid()
{

}

void CRegisterWid::initRegisterWid()
{
    QPalette Palette;
    //窗体
    setFixedSize(QSize(800, 450));
    setAutoFillBackground(true);//这句要加上，否则可能显示不出背景图
    Palette = this->palette();
    Palette.setBrush(QPalette::Window, QBrush(QPixmap(":/image/login02.png").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    setPalette(Palette);
    setWindowIcon(QIcon(QString(":/image/logo01.jpg")));
    setWindowTitle(QString("COSER社区"));
    // setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去掉标题栏
    // setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明

    //组件
    QHBoxLayout *hlay_1 = new QHBoxLayout();
    m_label_Logo->setText(QString("COSER"));
    m_label_Logo->setAlignment(Qt::AlignHCenter);
    m_label_Logo->setFixedHeight(15);
    m_label_Logo->setStyleSheet(QString("color:rgb(250,250,250); font-size:15px; font-weight:bold;"));
    hlay_1->setAlignment(Qt::AlignLeft);
    // hlay_1->setSpacing(0);
    // hlay_1->setContentsMargins(0, 0, 0, 0);
    hlay_1->addWidget(m_label_Logo);

    QHBoxLayout *hlay_2 = new QHBoxLayout();
    m_label_Register->setText(QString("COSER - Register"));
    m_label_Register->setAlignment(Qt::AlignHCenter);
    m_label_Register->setFixedSize(QSize(180, 30));
    m_label_Register->setStyleSheet(QString("color:rgb(250,250,250); font-size:15px; font-weight:bold;"));
    hlay_2->setAlignment(Qt::AlignHCenter);
    hlay_2->setSpacing(0);
    hlay_2->setContentsMargins(0, 0, 0, 0);
    hlay_2->addWidget(m_label_Register);

    QHBoxLayout *hlay_3 = new QHBoxLayout();
    m_ledit_UserName->setPlaceholderText(QString("用户名"));
    m_ledit_UserName->setEchoMode(QLineEdit::Normal);
    m_ledit_UserName->setAlignment(Qt::AlignHCenter);
    m_ledit_UserName->setFixedSize(QSize(180, 30));
    m_ledit_UserName->setStyleSheet(QString("background:transparent; border-style:none; color:rgb(250,250,250); font-weight:bold;"));
    hlay_3->setAlignment(Qt::AlignHCenter);
    hlay_3->setSpacing(0);
    hlay_3->setContentsMargins(0, 0, 0, 0);
    hlay_3->addWidget(m_ledit_UserName);

    QHBoxLayout *hlay_4 = new QHBoxLayout();
    m_ledit_PassWord->setPlaceholderText(QString("密码"));
    m_ledit_PassWord->setEchoMode(QLineEdit::Normal);
    m_ledit_PassWord->setAlignment(Qt::AlignHCenter);
    m_ledit_PassWord->setFixedSize(QSize(180, 30));
    // m_ledit_PassWord->setStyleSheet(QString("background:transparent; border-style:solid; border-color:rgb(210,210,210); border-bottom-width:2px; color:rgb(250,250,250); font-weight:bold;"));
    m_ledit_PassWord->setStyleSheet(QString("background:transparent; border-style:none; border-color:rgb(210,210,210); border-bottom-width:2px; color:rgb(250,250,250); font-weight:bold;"));
    hlay_4->setAlignment(Qt::AlignHCenter);
    hlay_4->setSpacing(0);
    hlay_4->setContentsMargins(0, 0, 0, 0);
    hlay_4->addWidget(m_ledit_PassWord);

    QHBoxLayout *hlay_5 = new QHBoxLayout();
    m_ledit_PhoneNum->setPlaceholderText(QString("手机号"));
    m_ledit_PhoneNum->setEchoMode(QLineEdit::Normal);
    m_ledit_PhoneNum->setAlignment(Qt::AlignHCenter);
    m_ledit_PhoneNum->setFixedSize(QSize(180, 30));
    m_ledit_PhoneNum->setStyleSheet(QString("background:transparent; border-style:none; color:rgb(250,250,250); font-weight:bold;"));
    hlay_5->setAlignment(Qt::AlignHCenter);
    hlay_5->setSpacing(0);
    hlay_5->setContentsMargins(0, 0, 0, 0);
    hlay_5->addWidget(m_ledit_PhoneNum);

    QHBoxLayout *hlay_6 = new QHBoxLayout();
    m_ledit_CheckNum->setPlaceholderText(QString("验证码"));
    m_ledit_CheckNum->setEchoMode(QLineEdit::Normal);
    m_ledit_CheckNum->setAlignment(Qt::AlignHCenter);
    m_ledit_CheckNum->setFixedSize(QSize(100, 30));
    m_ledit_CheckNum->setStyleSheet(QString("background:transparent; border-style:none; color:rgb(250,250,250); font-weight:bold;"));
    m_pbtn_GetCheckNum->setText(QString("获取验证码"));
    m_pbtn_GetCheckNum->setFixedSize(QSize(80, 30));
    m_pbtn_GetCheckNum->setStyleSheet(QString("background:transparent; border-style:none; color:rgba(250,250,250,50)"));
    // hlay_6->SetFixedSize(QSize(180, 30));
    hlay_6->setAlignment(Qt::AlignHCenter);
    hlay_6->setSpacing(0);
    hlay_6->setContentsMargins(0, 0, 0, 0);
    hlay_6->addWidget(m_ledit_CheckNum);
    hlay_6->addWidget(m_pbtn_GetCheckNum);

    QHBoxLayout *hlay_7 = new QHBoxLayout();
    m_pbtn_Register->setText(QString("注册"));
    // m_pbtn_Register->setCheckable(true);
    m_pbtn_Register->setFixedSize(QSize(180, 30));
    m_pbtn_Register->setStyleSheet(QString("QPushButton{background-color:rgb(250,150,180); color:white; border-radius:5px; border-style:none; font-weight:bold;}"
                                           "QPushButton:hover{background-color:rgb(250,110,150);}"      //鼠标悬停
                                           "QPushButton:pressed{background-color:rgb(250,150,180);}")); //鼠标按下
    hlay_7->setAlignment(Qt::AlignHCenter);
    hlay_7->setSpacing(0);
    hlay_7->setContentsMargins(0, 0, 0, 0);
    hlay_7->addWidget(m_pbtn_Register);

    QHBoxLayout *hlay_8 = new QHBoxLayout();
    m_pbtn_Login->setText(QString("登录账号"));
    m_pbtn_Login->setStyleSheet(QString("QPushButton{background:transparent; border-style:none; color:rgba(250,250,250,50); font-weight:normal;}"
                                        "QPushButton:hover{font-weight:bold;}"
                                        "QPushButton:pressed{font-weight:normal;}"));
    m_pbtn_MainWid->setText(QString("返回主页"));
    m_pbtn_MainWid->setStyleSheet(QString("QPushButton{background:transparent; border-style:none; color:rgba(250,250,250,50); font-weight:normal;}"
                                          "QPushButton:hover{font-weight:bold;}"
                                          "QPushButton:pressed{font-weight:normal;}"));
    hlay_8->setAlignment(Qt::AlignJustify);
    hlay_8->setSpacing(0);
    hlay_8->setContentsMargins(0, 0, 0, 0);
    hlay_8->addStretch(1);
    hlay_8->addWidget(m_pbtn_Login);
    hlay_8->addStretch(2);
    hlay_8->addWidget(m_pbtn_MainWid);
    hlay_8->addStretch(1);

    QVBoxLayout *vlay_1 = new QVBoxLayout();
    vlay_1->setAlignment(Qt::AlignHCenter);
    // vlay_1->setSpacing(0);//设置外边距
    // vlay_1->setContentsMargins(0, 0, 0, 0);//设置内边距
    vlay_1->addLayout(hlay_1);
    vlay_1->addStretch(1);//添加一个弹簧，伸缩因子为1
    vlay_1->addLayout(hlay_2);
    vlay_1->addLayout(hlay_3);
    vlay_1->addLayout(hlay_4);
    vlay_1->addLayout(hlay_5);
    vlay_1->addLayout(hlay_6);
    vlay_1->addLayout(hlay_7);
    vlay_1->addLayout(hlay_8);
    vlay_1->addStretch(1);//添加一个弹簧，伸缩因子为1
    m_wid_RegisterWid->setLayout(vlay_1);
    m_wid_RegisterWid->setFixedWidth(this->width() / 3);
    m_wid_RegisterWid->setAutoFillBackground(true);
    m_wid_RegisterWid->setAttribute(Qt::WA_TranslucentBackground, true);
    m_wid_RegisterWid->setAttribute(Qt::WA_NoSystemBackground, false);
    m_wid_RegisterWid->setWindowFlag(Qt::FramelessWindowHint, true);
    Palette = m_wid_RegisterWid->palette();
    Palette.setBrush(QPalette::Window, QBrush(QColor(100, 100, 100, 99)));
    m_wid_RegisterWid->setPalette(Palette);

    m_hlay_Main->setAlignment(Qt::AlignRight);
    m_hlay_Main->setSpacing(0);//设置外边距
    m_hlay_Main->setContentsMargins(0, 0, 0, 0);//设置内边距
    m_hlay_Main->addWidget(m_wid_RegisterWid);
    setLayout(m_hlay_Main);
}

void CRegisterWid::connectSignalSlot()
{
    connect(m_pbtn_GetCheckNum, &QPushButton::clicked, this, &CRegisterWid::clickedGetCheckNum_slot);
    connect(m_pbtn_Register, &QPushButton::clicked, this, &CRegisterWid::clickedRegister_slot);
    connect(m_pbtn_Login, &QPushButton::clicked, this, &CRegisterWid::clickedLogin_slot);
    connect(m_pbtn_MainWid, &QPushButton::clicked, this, &CRegisterWid::clickedMainWid_slot);
}

void CRegisterWid::checkInput()
{

}

void CRegisterWid::clickedGetCheckNum_slot()
{

}

void CRegisterWid::clickedRegister_slot()
{
    qDebug().noquote() << QString("[%1]:[%2]: =====").arg(__PRETTY_FUNCTION__).arg(__LINE__);
}

void CRegisterWid::clickedLogin_slot()
{

}

void CRegisterWid::clickedMainWid_slot()
{

}
