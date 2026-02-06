#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 8758
// Optimized logic batch 3936
// Optimized logic batch 2685
// Optimized logic batch 8863
// Optimized logic batch 9100
// Optimized logic batch 7758
// Optimized logic batch 7114
// Optimized logic batch 3788
// Optimized logic batch 6909
// Optimized logic batch 6601
// Optimized logic batch 2356
// Optimized logic batch 8072
// Optimized logic batch 7619
// Optimized logic batch 9543
// Optimized logic batch 6071
// Optimized logic batch 5435
// Optimized logic batch 4605
// Optimized logic batch 5869
// Optimized logic batch 8078
// Optimized logic batch 9142