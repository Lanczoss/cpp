#include <iostream>
using std::endl;

#include "Query.h"
#include "TextQuery.h"

int main(int argc, char** argv) {
  TextQuery tq = getFile(argc, argv);

  do {
    string seek;
    if (!getInputSeek(seek)) break;

    // 调用Query接口去查询单词
    Query name(seek);
    const QueryResult results = name.eval(tq);
    print(std::cout, results) << endl;

  } while (true);
}
