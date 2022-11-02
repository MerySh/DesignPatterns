#include <iostream>
#include <vector>
#include <memory>

class IComputerObject {
public:
    using IComputerObjectPtr = std::shared_ptr<IComputerObject>;

    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
};

class Mouse : public IComputerObject {
public:
    using MousePtr = std::shared_ptr<Mouse>;
    Mouse(int id) : m_id(id) {}

    void Connect() override
    {
        std::cout << "Connecting mouse with ID " << m_id << std::endl;
    }

    void Disconnect() override
    {
        std::cout << "Disconnecting mouse with ID " << m_id << std::endl;
    }

private:
    int m_id;
};

class Peripherals : public IComputerObject {
public:
    using PeripheralsPtr = std::shared_ptr<Peripherals>;
    Peripherals(int id) : m_id(id) {}

    void Connect() override
    {
        for (const auto& object : m_computerObjects) {
            object->Connect();
        }
     }

     void Disconnect() override
     {
         for (const auto& object : m_computerObjects) {
             object->Disconnect();
         }
                                        
     }

     void AddToPeripherals(const IComputerObjectPtr& computerObject)
     {
         m_computerObjects.push_back(computerObject);
     }

private:
    int m_id;
    std::vector<IComputerObjectPtr> m_computerObjects;
};

int main()
{
    IComputerObject::IComputerObjectPtr m1 = std::make_shared<Mouse>(1);
    IComputerObject::IComputerObjectPtr m2 = std::make_shared<Mouse>(2);
    IComputerObject::IComputerObjectPtr m3 = std::make_shared<Mouse>(3);
    
    Peripherals::PeripheralsPtr p1 = std::make_shared<Peripherals>(111);
    Peripherals::PeripheralsPtr p2 = std::make_shared<Peripherals>(112);
    
    p1->AddToPeripherals(m1);
    p2->AddToPeripherals(m2);
    p2->AddToPeripherals(m3);
    p1->AddToPeripherals(p2);

    p1->Connect();
    p1->Disconnect();

    return 0;                                            
}
