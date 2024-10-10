#include <iostream>
#include <string>

#include "Query.h"
#include "TextQuery.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
  // gets file to read and builds map to support queries
  TextQuery file = getFile(argc, argv);

  do {
    string sought1, sought2;
    // stop if hit eof on input or a "q" is entered
    if (!getInputSeeks(sought1, sought2)) break;

    // find all the occurrences of the requested string
    Query andq = Query(sought1) & Query(sought2);
    cout << "\nExecuting query for: " << andq << endl;
    QueryResult results = andq.eval(file);
    // report matches
    print(cout, results);

  } while (true);

  return 0;
}
