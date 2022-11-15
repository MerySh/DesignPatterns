#include <iostream>
#include <string>

class Client
{
public:
    Client* SetNext(Client* client)
    {
        ptr = client;
        return ptr;
    }

    virtual void Handler(int request, std::string ipAddress) = 0;
protected:
    Client* ptr;
};

class Receiver1 : public Client
{
public:
    void Handler(int request, std::string ipAddress) override
    {
        if (request == 1) {
            std::cout << "Receiver 1 from " << ipAddress << " IP address" << std::endl;
        } else {
            if (ptr != nullptr) {
                ptr->Handler(request, ipAddress);
            } else {
                std::cout << "Nullptr" << std::endl;
                return;
            }
        }
    }
};

class Receiver2 : public Client
{
public:
    void Handler(int request, std::string ipAddress) override
    {
        if (request == 2) {
            std::cout << "Receiver 2 from " << ipAddress << " IP address" << std::endl;
        } else {
            if (ptr != nullptr) {
                ptr->Handler(request, ipAddress);
            } else {
                std::cout << "Nullptr" << std::endl;
                return;
            }
        }
    }
};

class Receiver3 : public Client
{
public:
    void Handler(int request, std::string ipAddress) override
    {
        if (request == 3) {
            std::cout << "Receiver 3 from " << ipAddress  << " IP address" << std::endl;
        } else {
            if (ptr != nullptr) {
                ptr->Handler(request, ipAddress);
            } else {
                std::cout << "Nullptr" << std::endl;
                return;
            }
        }
    }
};

int main()
{
    Client* handler1 = new Receiver1;
    Client* handler2 = new Receiver2;
    Client* handler3 = new Receiver3;

    handler1->SetNext(handler2)->SetNext(handler3);
    handler1->Handler(1, "10.1.1.1");
    handler1->Handler(2, "10.1.1.2");
    handler1->Handler(3, "10.1.1.3");
    handler1->Handler(4, "10.1.1.4");

    return 0;
}
