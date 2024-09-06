#ifndef CREGISTERWID_H
#define CREGISTERWID_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAction>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QBrush>
#include <QColor>

class CRegisterWid : public QWidget
{
    Q_OBJECT
public:
    explicit CRegisterWid(QWidget *parent = nullptr);
    ~CRegisterWid();
private:
    QLabel *m_label_Logo = nullptr;
    QLabel *m_label_Register = nullptr;
    QLineEdit *m_ledit_UserName = nullptr;
    QLineEdit *m_ledit_PassWord = nullptr;
    QLineEdit *m_ledit_PhoneNum = nullptr;
    QLineEdit *m_ledit_CheckNum = nullptr;
    QPushButton *m_pbtn_GetCheckNum = nullptr;
    QPushButton *m_pbtn_Register = nullptr;
    QPushButton *m_pbtn_Login = nullptr;
    QPushButton *m_pbtn_MainWid = nullptr;
    QWidget *m_wid_RegisterWid = nullptr;
    QHBoxLayout *m_hlay_Main = nullptr;
public:
private:
    void initRegisterWid(void);
    void connectSignalSlot(void);
    void checkInput(void);
public:
private slots:
    void clickedGetCheckNum_slot(void);
    void clickedRegister_slot(void);
    void clickedLogin_slot(void);
    void clickedMainWid_slot(void);
public slots:
signals:
};

#endif // CREGISTERWID_H
