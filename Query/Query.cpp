#include "Query.h"

#include <algorithm>

#include "QueryResult.h"

QueryResult AndQuery::eval(const TextQuery &t) const {
  QueryResult left = _lhs.eval(t);
  QueryResult right = _rhs.eval(t);

  // 设置一个临时的存储行号的set
  shared_ptr<set<lines_t>> temp(new set<lines_t>);
  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                        std::inserter(*temp, temp->begin()));

  shared_ptr<int> tempi(new int(temp->size()));
  return QueryResult(rep(), temp, left.getLines(), tempi);
}

QueryResult OrQuery::eval(const TextQuery &t) const {
  QueryResult left = _lhs.eval(t);
  QueryResult right = _rhs.eval(t);
  shared_ptr<set<lines_t>> temp(new set<lines_t>(left.begin(), left.end()));
  temp->insert(right.begin(), right.end());
  shared_ptr<int> tempi(
      new int((*left.getDictSecond()) + (*right.getDictSecond())));
  return QueryResult(rep(), temp, left.getLines(), tempi);
}
