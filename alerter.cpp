#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
class ICNetworkStatus{
    public:
    virtual int networkAlert(float f_celcius) = 0;
};

class CNetWorkAlertStub : public ICNetworkStatus{
    public:
    int networkAlert(float f_celcius){
    if(f_celcius < 200){
        std::cout << "ALERT: Temperature is " << f_celcius << " celcius.\n";
        return 200;
    }
    else{
        std::cout << "ALERT: Temperature is " << f_celcius << " celcius.\n";
        return 500;
    }
    }
};

float convertFarenheitToCelcius(float farenhit){
    return ((farenhit - 32) * 5 / 9);
}

void alertInCelcius(float farenheit, ICNetworkStatus &f_networkStatus) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCodeFailure = f_networkStatus.networkAlert(celcius);
    if (returnCodeFailure != 200) {
        alertFailureCount += 1;
    }
}

void testNetworkStatus(){
    CNetWorkAlertStub m_networkAlert;
    alertInCelcius(200.5, m_networkAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(500.6, m_networkAlert);
    assert(alertFailureCount == 1);
}

int main() {
    testNetworkStatus();
    return 0;
}
