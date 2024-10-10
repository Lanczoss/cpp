#include <iostream>
#include <string>

#include "Query.h"
#include "TextQuery.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
  // gets file to read and builds map to support queries
  TextQuery file = getFile(argc, argv);

  // iterate with the user: prompt for a word to find and print results
  while (true) {
    string sought1, sought2, sought3;
    if (!getInputSeeks(sought1, sought2)) break;
    cout << "\nenter third word: ";
    cin >> sought3;
    // find all the occurrences of the requested string
    Query q = Query(sought1) & Query(sought2) | Query(sought3);
    cout << "\nExecuting Query for: " << q << endl;
    const QueryResult results = q.eval(file);
    // report matches
    print(cout, results);
  }
  return 0;
}
