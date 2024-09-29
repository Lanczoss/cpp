#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <string>
using namespace log4cpp;
using std::string;
#define processMsg(msg)                               \
  ((string(__FILE__) + " " + string(__func__) + " " + \
    std::to_string(__LINE__) + " " + msg)             \
       .c_str())
#define LogInfo(msg) Mylogger::getInstance()->info(processMsg(msg))
#define LogError(msg) Mylogger::getInstance()->error(processMsg(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(processMsg(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(processMsg(msg))

class Mylogger {
 public:
  static Mylogger *getInstance() {
    if (_pInstance == nullptr) {
      _pInstance = new Mylogger();
    }
    return _pInstance;
  }

  static void destroy() {
    if (_pInstance != nullptr) {
      delete _pInstance;
      _pInstance = nullptr;
    }
  }

  void warn(const char *msg) { root.warn(msg); }
  void error(const char *msg) { root.error(msg); }
  void debug(const char *msg) { root.debug(msg); }
  void info(const char *msg) { root.info(msg); }
  void fatal(const char *msg) { root.fatal(msg); }
  void crit(const char *msg) { root.crit(msg); }

 private:
  Mylogger() : root(Category::getRoot()) {
    root.setPriority(Priority::DEBUG);
    PatternLayout *pat = new PatternLayout();
    pat->setConversionPattern("%d [%p] %m%n");
    FileAppender *pfi = new FileAppender("file", "system.log");
    pfi->setLayout(pat);
    root.addAppender(pfi);
  }
  
  ~Mylogger() {
    Category::shutdown();
  }

 private:
  Category &root;
  static Mylogger *_pInstance;
};

Mylogger *Mylogger::_pInstance = nullptr;

void test0() {
  //第一步，完成单例模式的写法
  Mylogger *log = Mylogger::getInstance();
  log->info("The log is info message");
  log->error("The log is error message");
  log->fatal("The log is fatal message");
  log->crit("The log is crit message");
  Mylogger::destroy();
}

void test1() {
  printf("hello,world\n");
  //第二步，像使用printf一样
  //只要求能输出纯字符串信息即可，不需要做到格式化输出
  LogInfo("The log is info message");
  LogError("The log is error message");
  LogWarn("The log is warn message");
  LogDebug("The log is debug message");
  Mylogger::destroy();
}

int main(void) {
  /* test0(); */
  test1();
  return 0;
}
