# VerizonC-
CPlusPlus Interview Preparation

--------
#include <condition_variable>
#include <iostream>
#include <thread>

bool bReady = false;
std::mutex mutex_;
std::condition_variable condVar;

void waitingForWork(){
    {
        std::unique_lock<std::mutex> lck(mutex_);
        std::cout << "Waiting " << std::endl;
        condVar.wait(lck, [](){return bReady;});                       // (1)
    }
    std::cout << "Running " << std::endl;
}

void setDataReady(){
    {
        std::unique_lock<std::mutex> lck(mutex_);
        std::cout << "Data prepared" << std::endl;
        bReady = true;
    }
    condVar.notify_one();                   // (2)
}


int meal = 0;

// Consumer
void consumer(int orderNumber){
    std::unique_lock<std::mutex> lock(mutex_);
    while(meal == 0) {
        condVar.wait(lock);
    }
    
    cout<<"OrderNumberr: "<<orderNumber<<" being taking care of with "<< meal << " meals also ready."<<std::endl;
    --meal;
}

// Producer
void producer() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++meal;
    condVar.notify_one();
}

int main(int argc, const char * argv[]) {

//    std::cout << std::endl;
//
//    std::thread t1(waitingForWork);
//    std::thread t2(setDataReady);
//
//    t1.join();
//    t2.join();
//
//    std::cout << std::endl;
    
    
    std::thread chefs[10];
    std::thread waiters[10];
    
    /* Initialize customers and cheifs */
    for (int order = 0; order < 10; order++){
        chefs[order] = std::thread(producer);
        waiters[order] = std::thread(consumer, order);
    }
    
    /* Join the threads to the main threads */
    for (int order = 0; order < 10; order++) {
        waiters[order].join();
        chefs[order].join();
    }
 }
