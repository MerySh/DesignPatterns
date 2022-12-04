#include <iostream>

/* Abstract class */
class Target
{
    public:
        virtual void Request() = 0;
};

/*  */
class Adaptee {
    public:
        void SpecificRequest() {
            std::cout << "Specific Request" << std::endl;
        }
};

/* Adapter class for an objecct */
class Adapter: public Target {
    private:
        Adaptee* adaptee;
    
    public:
        Adapter(Adaptee* a): adaptee(a) {}
        void Request()
        {
            adaptee->SpecificRequest();
        }
};

/* Class Client for receiving a reference to target */
class Client {
    public:
        void ClientMethod(Target& t)
        {
            t.Request();
        }
        void ClientMethod(Target* t) 
        {
            t->Request();
        }
};

int main()
{
    Client client;
    Adaptee adaptee;
    Target* target;

    target = new Adapter(&adaptee);
    client.ClientMethod(target);
}
