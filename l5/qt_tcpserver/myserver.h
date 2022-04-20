#ifndef MYSERVER_H
#define MYSERVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTcpServer;
class QTextEdit;
class QTcpSocket;
QT_END_NAMESPACE

class MyServer : public QWidget
{
    Q_OBJECT

private:
    QTcpServer *m_ptcpServer = nullptr;
    QTextEdit  *m_ptxt = nullptr;
    quint16     m_nNextBlockSize;
    QTimer     *timer = nullptr;

private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);
    bool sendToFile(QTcpSocket* pSocket, const QString& filename,const size_t& fict,
                    const size_t& size_fict);

public:
    MyServer(int nPort,QWidget* pwgt = 0);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();

};

#endif
