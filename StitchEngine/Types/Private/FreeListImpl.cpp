#include "FreeList.hpp"

template <class T> FreeList<T>::FreeList() : first_free(-1) {}

template <class T> FreeList<T>::Handler FreeList<T>::Insert(const T &element) {
  if (first_free == -1) {
    int index = elements.size();
    FreeElement fElement = FreeElement{.data = element};
    Element element = Element{.element = fElement, .gen = 0};
    elements.push_back(element);
    return Handler{.index = index, .gen = 0};
  } else {
    int index = first_free;
    first_free = elements[first_free].element.next;
    elements[first_free].element.data = element;
    return Handler{.index = index, .gen = elements[index].gen};
  }
}

template <class T> void FreeList<T>::Erase(FreeList<T>::Handler handler) {
  assert(handler.index < elements.size());
  assert(elements[handler.index].element.gen == handler.gen);
  int index = handler.index;
  elements[index].gen++;
  elements[index].element.next = first_free;
  first_free = index;
}
