#ifndef CONSUMER_H_
#define CONSUMER_H_

class TaskQueue;

class Consumer {
 public:
  Consumer();
  ~Consumer();
  void consume(TaskQueue &taskqueue);
};

#endif  // !CONSUMER_H_
