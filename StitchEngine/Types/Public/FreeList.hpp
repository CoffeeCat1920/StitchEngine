#pragma once

#include <vector>

template <class T> class FreeList {
public:
  FreeList();

  int Insert(const T &element);
  void Erase(int n);
  void Clear();
  int Range() const;

  T &operator[](int n);

  // Returns the nth element.
  const T &operator[](int n) const;

private:
  union FreeElement {
    T element;
    int next;
  };
  std::vector<FreeElement> data;
  int first_free;
};
