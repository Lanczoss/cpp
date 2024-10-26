#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>

#include "ThreadPool.h"

using std::cout;
using std::endl;
using std::unique_ptr;

class MyTask {
 public:
  void process() {
    // 到底要执行什么任务呢？也就是业务逻辑是什么?
    ::srand(::clock());
    int num = ::rand() % 100;
    cout << ">>BO_ThreadPool.MyTask process " << num << endl;
  }
};

// 1、任务没有执行完毕，程序就退出来了?
// 原因：线程池启动之后，会创建工作线程，并且启动工作线程，也就是说
// 工作线程会执行线程入口函数doTask，如果主线程不添加任务，那么工作
// 线程会处于睡眠状态，但是如果主线程执行了addTask，添加了任务，那么
// 子线程（工作线程）会被唤醒，那么主线程与子线程都在运行。但是如果
// 主线程添加任务的速度比较快，那么很快就会执行到stop函数，那么如果
// 子线程的任务还没有执行完，主线程就已经进入了stop函数，那么会将
// 标志位_isExit设置为true，那么子线程可能就拿不到剩余的任务，就会
// 被退出,所以就看到了任务没有执行完，程序就退出来了
//
// 解决方案：在stop函数中，也就是即使主线程执行的要快，那么添加一个
// 判断，只要任务执行不完，主线程就不继续向下执行，也就是添加
//_taskQue.empty()操作，可以保证任务执行完毕
//
//
// 2、任务执行完毕了，但是程序无法正常退出？
// 原因：工作线程在执行doTask的时候，将最后一个任务通过getTask取出来
// 之后，这个时候子线程会继续执行任务，也就是执行process函数，但是
// 主线程也会继续从stop继续向下执行，也就是stop中的while循环不满足
// 条件，那么如果主线程执行的要快一些，可以很快的将标志位_isExit
// 设置为true，也是就子线程执行process比较慢，那么程序就可以退出来;
// 但是如果子线程执行process的速率比较快，主线程还没有来得及将标志位
//_isExit设置为true，那么子线程会继续进入到doTask的循环中,继续拿任务
// 但是任务队列已经为空了，那么子线程就会再次处于睡眠状态
//
// 解决方案：如果子线程执行的比较慢，程序不会有问题；但是如果子线程
// 跑的快，最终的结果是子线程会在_notEmpty条件变量上睡眠，可以让
// 主线程在回收之前将子线程全部唤醒后再回收
void test() {
  unique_ptr<MyTask> ptask(new MyTask());
  ThreadPool pool(4, 10);  // 创建线程池的对象

  // 启动线程池
  pool.start();

  int cnt = 20;
  while (cnt--) {
    // 添加任务
    //  pool.addTask(bind(&MyTask::process, ptask.get()));
    pool.addTask([&ptask]() { ptask.get(); });
    cout << "cnt = " << cnt << endl;
  }

  // 停止线程池
  pool.stop();
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
