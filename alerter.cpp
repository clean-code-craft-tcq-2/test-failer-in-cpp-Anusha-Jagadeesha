#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
class CNetworkStatus{
    public:
    virtual int networkAlertStub(float f_celcius) = 0;
};

class CNetWorkAlertSuccessStub : public CNetworkStatus{
    public:
    int networkAlertStub(float f_celcius){
    std::cout << "ALERT: Temperature is " << f_celcius << " celcius.\n";
    return 200;
    }
};

class CNetWorkAlertFailureStub : public CNetworkStatus{
    public:
    int networkAlertStub(float f_celcius){
    std::cout << "ALERT: Temperature is " << f_celcius << " celcius.\n";
    return 500;
    }
};

float convertFarenheitToCelcius(float farenhit){
    return ((farenhit - 32) * 5 / 9);
}

void alertInCelcius(float farenheit, CNetworkStatus &f_networkStatus) {
    float celcius = convertFarenheitToCelcius(farenheit);
    f_networkStatus.networkAlertStub(celcius);
    int returnCodeFailure = f_networkStatus.networkAlertStub(celcius);
    if (returnCodeFailure != 200) {
        alertFailureCount += 0;
    }
}

int main() {
    CNetWorkAlertSuccessStub m_networkAlertSuccess;
    CNetWorkAlertFailureStub m_networkAlertFailure;
    alertInCelcius(400.5, m_networkAlertSuccess);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, m_networkAlertFailure);
    assert(alertFailureCount == 1);
    return 0;
}

