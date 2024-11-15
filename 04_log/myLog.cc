#include <iostream>

#include "log4cpp/Appender.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"

int main(int argc, char** argv) {
  //创建自定义布局
  log4cpp::PatternLayout* pa1 = new log4cpp::PatternLayout();
  pa1->setConversionPattern("%d %c [%p] %m%n");

  log4cpp::PatternLayout* pa2 = new log4cpp::PatternLayout();
  pa1->setConversionPattern("%d %c [%p] %m%n");

  log4cpp::Appender* appender1 =
      new log4cpp::OstreamAppender("console", &std::cout);
  appender1->setLayout(pa1);

  log4cpp::Appender* appender2 =
      new log4cpp::FileAppender("default", "program.log");
  appender2->setLayout(pa2);

  log4cpp::Category& root = log4cpp::Category::getRoot();
  root.setPriority(log4cpp::Priority::WARN);
  root.addAppender(appender1);

  log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
  sub1.addAppender(appender2);

  // use of functions for logging messages
  root.error("root error");
  sub1.error("sub1 error");
  sub1.warn("sub1 warn");

  // printf-style for logging variables
  root.warn("%d + %d == %s ?", 1, 1, "two");


  return 0;
}
