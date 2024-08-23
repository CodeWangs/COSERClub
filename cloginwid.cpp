#include "cloginwid.h"

CLoginWid::CLoginWid(QWidget *parent)
    : QWidget{parent}
{
    m_label_Logo = new QLabel(this);
    m_label_Login = new QLabel(this);
    m_ledit_UserName = new QLineEdit(this);
    m_ledit_PassWord = new QLineEdit(this);
    m_pbtn_Login = new QPushButton(this);
    m_pbtn_Register = new QPushButton(this);
    m_pbtn_ForgetPass = new QPushButton(this);
    m_wid_LoginWid = new QWidget(this);
    m_hlay_Main = new QHBoxLayout();
    initLoginWid();
    connectSignalSlot();
}

CLoginWid::~CLoginWid()
{

}

void CLoginWid::initLoginWid()
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
    m_label_Login->setText(QString("COSER - Login"));
    m_label_Login->setAlignment(Qt::AlignHCenter);
    m_label_Login->setFixedSize(QSize(180, 30));
    m_label_Login->setStyleSheet(QString("color:rgb(250,250,250); font-size:15px; font-weight:bold;"));
    hlay_2->setAlignment(Qt::AlignHCenter);
    hlay_2->setSpacing(0);
    hlay_2->setContentsMargins(0, 0, 0, 0);
    hlay_2->addWidget(m_label_Login);

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
    m_ledit_PassWord->setEchoMode(QLineEdit::Password);
    m_ledit_PassWord->setAlignment(Qt::AlignHCenter);
    m_ledit_PassWord->setFixedSize(QSize(180, 30));
    m_ledit_PassWord->setStyleSheet(QString("background:transparent; border-style:solid; border-color:rgb(210,210,210); border-bottom-width:2px; color:rgb(250,250,250); font-weight:bold;"));
    hlay_4->setAlignment(Qt::AlignHCenter);
    hlay_4->setSpacing(0);
    hlay_4->setContentsMargins(0, 0, 0, 0);
    hlay_4->addWidget(m_ledit_PassWord);

    QHBoxLayout *hlay_5 = new QHBoxLayout();
    m_pbtn_Login->setText(QString("登录"));
    m_pbtn_Login->setFixedSize(QSize(180, 30));
    m_pbtn_Login->setStyleSheet(QString("background-color:rgb(250,150,180); color:white; border-radius:5px; border-style:none; font-weight:bold;"));
    hlay_5->setAlignment(Qt::AlignHCenter);
    hlay_5->setSpacing(0);
    hlay_5->setContentsMargins(0, 0, 0, 0);
    hlay_5->addWidget(m_pbtn_Login);

    QHBoxLayout *hlay_6 = new QHBoxLayout();
    m_pbtn_Register->setText(QString("注册账号"));
    m_pbtn_Register->setStyleSheet(QString("background:transparent; border-style:none; color:rgba(250,250,250,50)"));
    m_pbtn_ForgetPass->setText(QString("忘记密码?"));
    m_pbtn_ForgetPass->setStyleSheet(QString("background:transparent; border-style:none; color:rgba(250,250,250,50)"));
    hlay_6->setAlignment(Qt::AlignJustify);
    hlay_6->setSpacing(0);
    hlay_6->setContentsMargins(0, 0, 0, 0);
    hlay_6->addStretch(1);
    hlay_6->addWidget(m_pbtn_Register);
    hlay_6->addStretch(2);
    hlay_6->addWidget(m_pbtn_ForgetPass);
    hlay_6->addStretch(1);

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
    vlay_1->addStretch(1);//添加一个弹簧，伸缩因子为1
    m_wid_LoginWid->setLayout(vlay_1);
    m_wid_LoginWid->setFixedWidth(this->width() / 3);
    m_wid_LoginWid->setAutoFillBackground(true);
    m_wid_LoginWid->setAttribute(Qt::WA_TranslucentBackground, true);
    m_wid_LoginWid->setAttribute(Qt::WA_NoSystemBackground, false);
    m_wid_LoginWid->setWindowFlag(Qt::FramelessWindowHint, true);
    Palette = m_wid_LoginWid->palette();
    Palette.setBrush(QPalette::Window, QBrush(QColor(100, 100, 100, 99)));
    m_wid_LoginWid->setPalette(Palette);

    m_hlay_Main->setAlignment(Qt::AlignLeft);
    m_hlay_Main->setSpacing(0);//设置外边距
    m_hlay_Main->setContentsMargins(0, 0, 0, 0);//设置内边距
    m_hlay_Main->addWidget(m_wid_LoginWid);
    setLayout(m_hlay_Main);

}

void CLoginWid::connectSignalSlot()
{

}
