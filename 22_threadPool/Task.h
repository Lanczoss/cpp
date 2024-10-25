#ifndef TASK_H_
#define TASK_H_

class Task {
 public:
  Task();
  virtual ~Task();
  virtual void process() = 0;
};

#endif  // !TASK_H_
