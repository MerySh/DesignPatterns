#include <iostream>
#include <string>
#include <list>

class Subject;

class Observer
{
public:
    virtual void update(Subject& subject) = 0;
};

class Subject
{
public:
    void addObserver(Observer& observer)
    {
        observers.push_back(&observer);
    }
    void notify()
    {
        for (auto i = observers.begin(); i != observers.end(); ++i) {
            (*i)->update(*this);
        }
    }
    void setTask(std::string t)
    {
        task = t;
        notify();
    }
    std::string getTask()
    {
        return task;
    }
private:
    std::list<Observer*> observers;
    std::string task;
};

class TaskObserver : public Observer
{
public:
    void update(Subject &subject) {
        std::cout << "Task changed to '" << subject.getTask() << "' " << std::endl;
    }    
};

class CountObserver : public Observer
{
public:
    CountObserver()
    {
        count = 0;
    }
    void update(Subject &subject)
    {
        count++;
        std::cout << "Updated " << count << " times" << std::endl;
    }
private:
    int count;
};

int main()
{
    Subject subject;
    
    subject.addObserver(*new TaskObserver);
    subject.addObserver(*new CountObserver);
    subject.setTask("Change ABC function!");
    subject.setTask("Move ABC function to the end of the code!");

    return 0;
}
