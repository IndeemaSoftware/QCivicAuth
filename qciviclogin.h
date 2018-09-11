#ifndef EECIVICLOGININ_H
#define EECIVICLOGININ_H

#include <QWidget>

#include <QSslError>
#include <QString>

class QWebEngineView;
class QWebEnginePage;
class QVBoxLayout;
class QTimer;

/**
 * @brief The EECivicLoginIn class
 * Class, which allows to demonstate gui form of civic signing in
 */
class QCivicLogIn :  public QWidget
{
    Q_OBJECT
public:
    QCivicLogIn(QWidget *parent = 0);


signals:
    /**
     * @brief receivedToken
     * Signal, which will be emitted after read civic token from web-page
     */
    void receivedToken(QString);

public slots:

    /**
     * @brief EECivicLoginIn::uploadPage
     * Upload civic page and start time for checking of the token tag value
     */
    void uploadPage();

    /**
     * @brief EECivicLoginIn::readTokenTag
     * Try to read value from token tag
     * If has been read succesfully - close window and emit signal about token receiving
     */
    void readTokenTag();

private:
    QWebEngineView *mWebView;
    QWebEnginePage *mWebPage;
    QVBoxLayout *mBoxLayout;
    QTimer *mTimer;

    static const QString mCivicAddress;
    static constexpr int mTimerDelay = 1000;
};

#endif // EECIVICLOGININ_H
