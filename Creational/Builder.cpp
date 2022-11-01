#include <iostream>

/* Smartphone parts */
class Camera {
    public:
        int megapixels;
};

class Memory {
    public:
        int size;
};

class Display {
    public:
        float size;
};

/* My product is Smartphone */
class Smartphone {
    public:
        Camera*  camera;
        Memory*  memory;
        Display* display;

        void specifications()
        {
            std::cout << "camera:  " << camera->megapixels << " megapixels" << std::endl;
            std::cout << "memory:  " << memory->size << " GB" << std::endl;
            std::cout << "display: " << display->size << " inches" << std::endl;
        }
};

/* Builder class is responsible for making Smartphone parts */
class Builder {
    public:
        virtual Camera* getCamera() = 0;
        virtual Memory* getMemory() = 0;
        virtual Display* getDisplay() = 0;
};

/* Director class is responsible for the whole process */
class Director {
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder) {
            builder = newBuilder;
        }

        Smartphone* getSmartphone()
        {
            Smartphone* smartphone = new Smartphone();

            smartphone->camera = builder->getCamera();
            smartphone->memory = builder->getMemory();
            smartphone->display = builder->getDisplay();

            return smartphone;
        }
};

/* Builder for Iphone 11pro Smartphone */
class Iphone11proBuilder: public Builder {
    public:
        Camera* getCamera()
        {
            Camera* camera = new Camera();
            camera->megapixels = 12;
        
            return camera;
        }

        Memory* getMemory()
        {
            Memory* memory = new Memory();
            memory->size = 256;

            return memory;
        }

        Display* getDisplay()
        {
            Display* display = new Display();
            display->size = 5.85;

            return display;
        }
};

/* Builder for Iphone 14pro Smartphone */
class Iphone14proBuilder: public Builder {
    public:
        Camera* getCamera()
        {
            Camera* camera = new Camera();
            camera->megapixels = 48;
        
            return camera;
        }

        Memory* getMemory()
        {
            Memory* memory = new Memory();
            memory->size = 512;

            return memory;
        }

        Display* getDisplay()
        {
            Display* display = new Display();
            display->size = 6.7;

            return display;
        }
};

int main()
{
    Smartphone* smartphone; // My final product
    Director director; // Me who will control the process

    Iphone11proBuilder iphone11proBuilder; // Builder for my current Smartphone
    Iphone14proBuilder iphone14proBuilder; // Builder for my desired Smartphone
    
    /* Build Iphone 11pro */
    std::cout << "Iphone 11pro" << std::endl;
    director.setBuilder(&iphone11proBuilder);
    smartphone = director.getSmartphone();
    smartphone->specifications();

    std::cout << std::endl << std::endl;

    /* Build Iphone 14pro */
    std::cout << "Iphone 14pro" << std::endl;
    director.setBuilder(&iphone14proBuilder);
    smartphone = director.getSmartphone();
    smartphone->specifications();

    return 0;
}
