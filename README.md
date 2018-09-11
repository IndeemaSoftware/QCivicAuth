![](https://github.com/IndeemaSoftware/SmartLock/blob/Assets/indeema_logo.jpg?raw=true)
# QCivicAuth
Qt C++ desktop and mobile SDK for civic authentication

qpm install com.indeema.qcivicauth

Before starting using civic don't forget load [standart civic page] (https://github.com/IndeemaSoftware/QCivicAuth/blob/master/index.html) with your usnique app id to you website with domain name and register that domain name in Civic admin panel, other way youn't be able to use this SDK.


```
    QCivicLogIn *mCivicLogin = new QCivicLogIn();
    if (!mCivicLogin->setCivicAddress("https://internxt.com/civic")) {
        qDebug() << "Warning: Civic url page is invalid. But we still store it";
    }
    
    connect(mCivicLogin, SIGNAL(receivedToken(QString)), this, SLOT(logedToCivic(QString)));
    
    mCivicLogin->uploadPage();
```

as a parameter in logedToCivic you will get civic token.
