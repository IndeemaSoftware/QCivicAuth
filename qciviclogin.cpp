#include "qciviclogin.h"
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWebEngineSettings>

#include <QSslConfiguration>
#include <QNetworkReply>
#include <QTimer>
#include <QFile>
#include <QCloseEvent>
#include <QMoveEvent>

QCivicLogIn::QCivicLogIn(QWidget *parent):
    QWidget{parent}
{   
    this->setGeometry(this->geometry().x(), this->geometry().y(), 300, 400);
    mWebPage = new QWebEnginePage(this);
    mWebView = new QWebEngineView(this);
    mTimer = new QTimer(this);

    mWebView->setPage(mWebPage);
    mBoxLayout = new QVBoxLayout(this);
    mBoxLayout->addWidget(mWebView);
    mBoxLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mBoxLayout);
    connect(mWebView, SIGNAL(loadFinished(bool)), this, SLOT(show()));
    connect(mTimer, SIGNAL(timeout()), this, SLOT(readTokenTag()));
}
/**
 * @brief EECivicLoginIn::uploadPage
 * Upload civic page and start time for checking of the token tag value
 */
void QCivicLogIn::uploadPage()
{
    mWebView->load(QUrl(mCivicAddress));
    mTimer->start(mTimerDelay);
}

/**
 * @brief EECivicLoginIn::readTokenTag
 * Try to read value from token tag
 * If has been read succesfully - close window and emit signal about token receiving
 */
void QCivicLogIn::readTokenTag()
{
    qDebug() << "EECivicLoginIn::readTag()";
    mWebView->page()->runJavaScript(QString("document.getElementById('token').innerHTML"),
                                    [this](const QVariant &result) {
        QString lToken = result.toString();
        if (!lToken.isEmpty()) {
            qDebug() << "Result:" << lToken;
            mTimer->stop();
            this->close();
            emit receivedToken(lToken);
        }
    });
}

void QCivicLogIn::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
}

void QCivicLogIn::moveEvent(QMoveEvent *event)
{
    this->resize(width(),height());
    QWidget::moveEvent(event);
}

QString QCivicLogIn::civicAddress() const
{
    return mCivicAddress;
}

bool QCivicLogIn::setCivicAddress(QString address)
{
    mCivicAddress = address;
    return QUrl(address).isValid();
}
