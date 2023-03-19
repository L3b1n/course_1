#pragma once
#include <cstddef>
#include <list>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <iostream>

struct KNoEmplace__ {};
struct KEmplace__ {};

template <typename Type> 
class Node 
{
public:
    Type element;
    Node<Type>* prev;
    Node<Type>* next;

public:
    Node(KNoEmplace__ const& aNoEmpl) : element{}, prev(nullptr), next(nullptr){};
    Node(KNoEmplace__ const& aNoEmpl,const Node& node) : Node(node.element, node.prev, node.next) {};
    template <typename ... Args>
    Node(KEmplace__ const& aNoEmpl,Args &&... val) : element(std::forward<Args>(val)...), next(nullptr),prev(nullptr) {}
};

template <typename Type> class Iterator 
{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = std::remove_cv_t<Type>;
    using pointer = Type*;
    using reference = Type&;
    using iterator_category = std::random_access_iterator_tag;

public:
    explicit Iterator(Node<Type>* ptr = nullptr);
    Iterator(const Iterator& iterator);

    ~Iterator() = default;

    bool operator==(const Iterator& lhs) const;
    bool operator!=(const Iterator& lhs) const;

    Iterator operator++();
    //    Iterator operator++(int post);
    Iterator operator--();
    //    Iterator operator--(int post);

    Type& operator*();

protected:
    Node<Type>* date;
};

namespace std 
{
    template <typename Type> struct iterator_traits<Iterator<Type>> 
    {
        using difference_type = std::ptrdiff_t;
        using value_type = std::remove_cv_t<Type>;
        using pointer = Type*;
        using reference = Type&;
        using iterator_category = std::random_access_iterator_tag;
    };
} // namespace std

//-------------------------------------------------------------------------------------------------
template <typename Type>
Iterator<Type>::Iterator(Node<Type>* ptr) : date(ptr) {}

//-------------------------------------------------------------------------------------------------
template <typename Type>
Iterator<Type>::Iterator(const Iterator& iter) : Iterator(iter.date) {}

//-------------------------------------------------------------------------------------------------
template <typename Type>
bool Iterator<Type>::operator == (const Iterator& lhs) const { return (date == lhs.date);}

//-------------------------------------------------------------------------------------------------
template <typename Type>
bool Iterator<Type>::operator != (const Iterator& lhs) const { return (date != lhs.date);}

//-------------------------------------------------------------------------------------------------
template <typename Type> Iterator<Type> Iterator<Type>::operator ++ () 
{
    date = date->next;
    return *this;
}

//-------------------------------------------------------------------------------------------------
// template <typename Type>
// Iterator<Type> Iterator<Type>::operator++(int post)
//{
//    Iterator<Type> temp(date);
//    date = date->next;
//    return temp;
//}

//-------------------------------------------------------------------------------------------------
template <typename Type> Iterator<Type> Iterator<Type>::operator -- () 
{
    date = date->prev;
    return *this;
}

//-------------------------------------------------------------------------------------------------
// template <typename Type>
// Iterator<Type> Iterator<Type>::operator--(int post)
//{
//    Iterator<Type> temp(date);
//    date = date->prev;
//    return temp;
//}

//-------------------------------------------------------------------------------------------------
template <typename Type> Type& Iterator<Type>::operator * () { return date->element;}

template <typename Type>
class Deque 
{
public:
    using iterator = Iterator<Type>;
    using const_iterator = Iterator<const Type>;
    using reverse_iterator = std::reverse_iterator<Iterator<Type>>;
    using const_reverse_iterator = std::reverse_iterator<Iterator<const Type>>;

public:
    Deque();
    Deque(const Deque& deq);
    Deque(Deque&& deq) noexcept;
    Deque(std::initializer_list<Type> list);
    Deque& operator = (const Deque& deq);
    Deque& operator = (Deque&& deq);
    ~Deque();

    const Type& front() const;
    const Type& back() const;

    iterator begin() { return iterator(head);}
    iterator end() { return iterator(tail->next);}

    reverse_iterator rbegin() { return std::make_reverse_iterator(this->end());}
    reverse_iterator rend() { return std::make_reverse_iterator(this->begin());}

    bool empty() const;
    size_t size() const;

    void push_front(const Type& tp);
    void push_back(const Type& tp);

    template <typename ... Args>
    void emplace_front(Args&& ...val);
    template <typename ... Args>
    void emplace_back(Args&& ...val);

    void pop_front();
    void pop_back();

    void clear() noexcept;

private:
    size_t count{};
    Node<Type>* head;
    Node<Type>* tail;
};

////<swap trick move>
//template <typename Type>
//void Deque<Type>::swap(Deque& deq) noexcept
//{
//    Deque temp(deq);
//    deq = std::move(*this);
//    *this = std::move(temp);
//}

template <typename Type>
size_t Deque<Type>::size() const { return count;}

template <typename Type>
bool Deque<Type>::empty() const { return head == nullptr;}

//Default  constructor 
template <typename Type>
Deque<Type>::Deque() : count(0), head(nullptr), tail(nullptr) {}

//Default destructor
template <typename Type>
Deque<Type>::~Deque()
{
    //while (head)
    //{
    //    Node<Type>* p = head;
    //    head = head->next;
    //    delete p;
    //}
    //count = 0;
    clear();
}

//Copy constructor
template <typename Type>
Deque<Type>::Deque(const Deque& deq) : count(deq.count), head(nullptr), tail(nullptr)
{
    for(const Node<Type>* p = deq.head; p != nullptr; p = p->next)
    {
        Node<Type>* p_new = new Node<Type>(KNoEmplace__());
        p_new->element = p->element;
        if(head == nullptr && tail == nullptr)
        {
            head = p_new;
            tail = head;
        }
        else
        {
            tail->next = p_new;
            p_new->prev = tail;
            p_new->next = nullptr;
            tail = p_new;
        }
    }
}

//Move constructor
template <typename Type>
Deque<Type>::Deque(Deque&& deq) noexcept : count(deq.count), head(deq.head), tail(deq.tail)
{
    deq.count = 0;
    deq.head = nullptr;
    deq.tail = nullptr;
}

template<typename Type>
inline Deque<Type>::Deque(std::initializer_list<Type> list) : head(nullptr), tail(nullptr)
{
    for(Type x : list)
    {
        push_back(x);
        count++;
    }
}

//Copy operator ==
template <typename Type>
Deque<Type>& Deque<Type>::operator = (const Deque& deq)
{
    if(this == &deq){ return *this;}
    Deque tmp(deq);
    std::swap(count, tmp.count);
    std::swap(head, tmp.head);
    std::swap(tail, tmp.tail);
    return *this;
}

//Move operator ==
template <typename Type>
Deque<Type>& Deque<Type>::operator = (Deque&& deq)
{
    if(this == &deq) { return *this;}
    clear();
    std::swap(count, deq.count);
    std::swap(head, deq.head);
    std::swap(tail, deq.tail);
    return *this;
}

template <typename Type>
void Deque<Type>::push_front(const Type& tp)
{
    Node<Type>* p_new = new Node<Type>(KNoEmplace__());
    p_new->element = tp;
    
    if(head == nullptr && tail == nullptr)
    {
        head = p_new;
        tail = head;
    }
    else
    {
        p_new->next = head;

        head->prev = p_new;
        head = p_new;
    }
    ++count;
 
}

template <typename Type>
const Type& Deque<Type>::front() const
{
    if(empty()){ throw std::out_of_range("ERROR : front is not allowed : deque is empty ");}
    return head->element;
}

template <typename Type>
void Deque<Type>::push_back(const Type& tp)
{
    Node<Type>* p_new = new Node<Type>(KNoEmplace__());
    p_new->element = tp;
    if(head == nullptr && tail == nullptr)
    {
        head = p_new;
        tail = head;
    }
    else
    {
        tail->next = p_new;
        p_new->prev = tail;
        p_new->next = nullptr;
        tail = p_new;
    }
    ++count;
}

template <typename Type>
const Type& Deque<Type>::back() const
{
    if(empty()){ throw std::out_of_range("ERROR : back is not allowed : deque is empty");}
    return tail->element;
}

template <typename Type>
void Deque<Type>::pop_front()
{
    if(empty()){ throw std::out_of_range("ERROR : pop_front is not allowed : deque is empty");}

    if(head == tail)
    {
        delete head;
        --count;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<Type>* p = head;
    head = head->next;
    head->prev = nullptr;
    --count;
    delete p;
}

template <typename Type>
void Deque<Type>::pop_back()
{
    if(empty()){ throw std::out_of_range("ERROR : pop_back is not allowed : deque is empty");}

    if(head == tail)
    {
        delete head;
        --count;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<Type>* p = tail;
    tail = tail->prev;
    tail->next = nullptr;
    --count;
    delete p;
}

template <typename Type>
void Deque<Type>::clear() noexcept
{
    while(!empty()){ pop_back();}
}

template<typename Type>
template<typename ...Args>
inline void Deque<Type>::emplace_front(Args && ...val)
{
    auto* p_new = new Node<Type>(KEmplace__(),std::forward<Args>(val)...);
    if(head == nullptr && tail == nullptr)
    {
        head = tail = p_new;
    }
    else
    {
        p_new->next = head;
        head->prev = p_new;
        head = p_new;
    }
    ++count;
}

template<typename Type>
template<typename ...Args>
inline void Deque<Type>::emplace_back(Args && ...val)
{
    auto* p_new = new Node<Type>(KEmplace__(), std::forward<Args>(val)...);
    if(head == nullptr && tail == nullptr)
    {
        head = p_new;
        tail = head;
    }
    else
    {
        tail->next = p_new;
        p_new->prev = tail;
        p_new->next = nullptr;
        tail = p_new;
    }
    ++count;
}