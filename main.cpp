#include "ThreadPool.h"
void func(void* arg)
{
    int* p = (int*)arg;
    std::cout << "thread " << std::this_thread::get_id() << " is working, number = " << *p << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    delete p;
}

int main()
{
    ThreadPool pool(20, 2, 100);

    // 记录开始时间
    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i < 500; i++)
    {
        int* p = new int;
        *p = i + 100;
        pool.addTask(func, p);
    }
    // 记录结束时间
    auto end = std::chrono::steady_clock::now();
    std::cout << "addTask() time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
}
