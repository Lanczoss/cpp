#include <functional>
using std::function;

class Figure {
 public:
  using DisplayCallback = function<void()>;
  using AreaCallback = function<double()>;
  void setDisplayCallback(DisplayCallback &&cb) {
    _displayCallback = std::move(cb);
  }

  void setAreaCallback(AreaCallback &&cb) { _areaCallback = std::move(cb); }

  void handleDisplayCallback() const {
    if (_displayCallback) {
      _displayCallback();
    }
  }

  double handleAreaCallback() const {
    if (_areaCallback) {
      return _areaCallback();
    } else {
      return 0;
    }
  }

  DisplayCallback _displayCallback;
  AreaCallback _areaCallback;
};
