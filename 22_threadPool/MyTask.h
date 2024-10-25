#ifndef MYTASK_H_
#define MYTASK_H_

#include "Task.h"

class MyTask : public Task {
 public:
  virtual void process() override;
};

#endif  // !MYTASK_H_
