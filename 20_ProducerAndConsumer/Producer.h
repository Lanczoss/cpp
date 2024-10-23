#ifndef PRODUCER_H_
#define PRODUCER_H_

class TaskQueue;

class Producer {
 public:
  Producer();
  ~Producer();

  void produce(TaskQueue &taskqueue);
};

#endif  // !PRODUCER_H_
