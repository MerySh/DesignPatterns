#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

#define MAX_TIMES 5

/* Server like Singleton class must be one instance */
class Server {
private:
    static Server *instance;
    static std::mutex mutex;

    Server() 
    {
        std::cout << "Created Server..." << std::endl; 
    }

    ~Server() 
    {
        std::cout << "Destroyed Server..." << std::endl;
    }

public:
    Server(Server&) = delete;
    void operator=(const Server&) = delete;

    static Server *createInstance() 
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new Server;                              
        }
        return instance;                       
    }

    static void destroyInstance()
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
};

Server *Server::instance = nullptr;
std::mutex Server::mutex;

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < MAX_TIMES; ++i) {
        threads.emplace_back(std::thread([]() {
            Server::createInstance();
            Server::destroyInstance();
        }));
    }

    for (auto& t: threads) {
        if (t.joinable()) {
            t.join();
        }
    }

/*
    Server *server1 = server1->getInstance();
    Server *server2 = server2->getInstance();

    std::cout << server1->getClientNum() << std::endl;

    server1->setClientNum(10);
    server2->setClientNum(20);
       
    std::cout << server1->getClientNum() << std::endl;
    std::cout << server2->getClientNum() << std::endl;
*/  
    return 0;
}
