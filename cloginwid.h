#ifndef CLOGINWID_H
#define CLOGINWID_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QBrush>
#include <QColor>

class CLoginWid : public QWidget
{
    Q_OBJECT
public:
    explicit CLoginWid(QWidget *parent = nullptr);
    ~CLoginWid();
private:
    QLabel *m_label_Logo = nullptr;
    QLabel *m_label_Login = nullptr;
    QLineEdit *m_ledit_UserName = nullptr;
    QLineEdit *m_ledit_PassWord = nullptr;
    QPushButton *m_pbtn_Login = nullptr;
    QPushButton *m_pbtn_Register = nullptr;
    QPushButton *m_pbtn_ForgetPass = nullptr;
    QWidget *m_wid_LoginWid = nullptr;
    QHBoxLayout *m_hlay_Main = nullptr;
public:
private:
    void initLoginWid(void);
    void connectSignalSlot(void);
public:
private slots:
public slots:
signals:
};

#endif // CLOGINWID_H
