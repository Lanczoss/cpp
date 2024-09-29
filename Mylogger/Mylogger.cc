#include "Mylogger.hh"

#include <iostream>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using namespace log4cpp;
using std::cout;

Mylogger *Mylogger::_pInstance = nullptr;

Mylogger *Mylogger::getInstance() {
  if (_pInstance == nullptr) {
    _pInstance = new Mylogger();
  }
  return _pInstance;
}

void Mylogger::destroy() {
  if (_pInstance != nullptr) {
    delete _pInstance;
    _pInstance = nullptr;
  }
}

Mylogger::Mylogger() : _mycat(Category::getRoot().getInstance("mycat")) {
  PatternLayout *ptn1 = new PatternLayout();
  ptn1->setConversionPattern("%d %c [%p] %m%n");

  PatternLayout *ptn2 = new PatternLayout();
  ptn2->setConversionPattern("%d %c [%p] %m%n");

  OstreamAppender *pos = new OstreamAppender("console", &cout);
  pos->setLayout(ptn1);

  FileAppender *pfile = new FileAppender("file", "wd.txt");
  pfile->setLayout(ptn2);

  _mycat.setPriority(Priority::DEBUG);
  _mycat.addAppender(pos);
  _mycat.addAppender(pfile);
}

void Mylogger::warn(const char *msg) { _mycat.warn(msg); }
void Mylogger::error(const char *msg) { _mycat.error(msg); }
void Mylogger::debug(const char *msg) { _mycat.debug(msg); }
void Mylogger::info(const char *msg) { _mycat.info(msg); }
void Mylogger::fatal(const char *msg) { _mycat.fatal(msg); }
void Mylogger::crit(const char *msg) { _mycat.crit(msg); }

