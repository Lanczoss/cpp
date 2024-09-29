#ifndef MYLOGGER_HH_
#define MYLOGGER_HH_

#include <log4cpp/Category.hh>

class Mylogger {
 public:
  static Mylogger *getInstance();
  static void destroy();
  void warn(const char *msg);
  void error(const char *msg);
  void debug(const char *msg);
  void info(const char *msg);
  void fatal(const char *msg);
  void crit(const char *msg);

  Mylogger(const Mylogger &) = delete;
  Mylogger &operator=(const Mylogger &) = delete;

 private:
  Mylogger();
  /* ~Mylogger(); */

 private:
  log4cpp::Category &_mycat;
  static Mylogger *_pInstance;
};


#endif
