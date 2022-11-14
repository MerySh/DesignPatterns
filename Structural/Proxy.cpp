#include <iostream>

class ATM
{
public:
    virtual void request() = 0;
};

class Bank : public ATM
{
public:
    void request()
    {
        std::cout << "Requested to the Bank" << std::endl;
    }
};

class Proxy : public ATM
{
public:
    Proxy (Bank *real_subj) : bank(new Bank(*real_subj)) {}
    ~Proxy()
    {
        delete bank;
    }

    void request() override
    {
        this->bank->request();
        std::cout << "Requested via Proxy" << std::endl;
    }

private:
    Bank *bank;
};

int main()
{
    std::cout << "--- Real subject ---" << std::endl;
    Bank *bank = new Bank;
    bank->request();

    std::cout << "--- Proxy ---" << std::endl;
    Proxy *proxy = new Proxy(bank);
    proxy->request();

    delete bank;
    delete proxy;

    return 0;
}
