![](https://github.com/IndeemaSoftware/SmartLock/blob/Assets/indeema_logo.jpg?raw=true)
# QCivicAuth
Qt C++ desktop and mobile SDK for civic authentication

qpm install com.indeema.qcivicauth

Before starting using civic don't forget load [standart civic page] (https://github.com/IndeemaSoftware/QCivicAuth/blob/master/index.html) with your usnique app id to you website with domain name and register that domain name in Civic admin panel, other way youn't be able to use this SDK.


```cpp
    QCivicLogIn *mCivicLogin = new QCivicLogIn();
    if (!mCivicLogin->setCivicAddress("Some unique address where index.html with civic data is located")) {
        qDebug() << "Warning: Civic url page is invalid. But we still store it";
    }
    
    connect(mCivicLogin, SIGNAL(receivedToken(QString)), this, SLOT(logedToCivic(QString)));
    
    mCivicLogin->uploadPage();
```

as a parameter in logedToCivic you will get civic token.

To know more about us and our [Web expertise](https://indeema.com/services/webdevelopment), visit our website https://indeema.com
