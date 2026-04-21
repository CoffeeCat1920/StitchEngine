#pragma once

#include <cassert>
#include <vector>

template <class T> class FreeList {
public:
  FreeList() : first_free(-1) {}

  int Insert(const T &element) {
    if (first_free != -1) {
      int index = first_free;
      first_free = data[first_free].next;
      data[index].element = element;
      return index;
    } else {
      FreeElement fe;
      new (&fe.element) T(element); // placement new to construct T
      data.push_back(fe);
      return static_cast<int>(data.size()) - 1;
    }
  }

  void Erase(int n) {
    assert(n >= 0 && n < static_cast<int>(data.size()));
    data[n].next = first_free;
    first_free = n;
  }

  void Clear() {
    data.clear();
    first_free = -1;
  }

  int Range() const { return static_cast<int>(data.size()); }

  T &operator[](int n) {
    assert(n >= 0 && n < static_cast<int>(data.size()));
    return data[n].element;
  }

  const T &operator[](int n) const {
    assert(n >= 0 && n < static_cast<int>(data.size()));
    return data[n].element;
  }

private:
  union FreeElement {
    T element;
    int next;

    FreeElement() {}
    ~FreeElement() {}
  };

  std::vector<FreeElement> data;
  int first_free;
};
