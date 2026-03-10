#pragma once

#include <vector>

template <class T> class FreeList {
public:
  FreeList();

  struct Handler {
    int index;
    int gen = 0;
  };

  Handler Insert(const T &element);
  void Erase(Handler handler);
  void Clear();

  T &operator[](Handler handler);
  const T &operator[](Handler handler) const;

private:
  union FreeElement {
    T data;
    int next;
  };

  struct Element {
    FreeElement element;
    int gen;
  };

  std::vector<Element> elements;

  int first_free;
};
