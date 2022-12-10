//----------------------------------------------------------------------
//Реализовать параметризованный класс KQueueOnList, представляющий такую
//структуру данных как очередь. Класс для реализации очереди использует 
//однонаправленный список.
//----------------------------------------------------------------------

#include <cstddef>//принята
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
    Node(KNoEmplace__ const& aNoEmpl, Type const e) : element{e}, prev(nullptr), next(nullptr) {};
    Node(KNoEmplace__ const& aNoEmpl, const Node& node) : Node(node.element, node.prev, node.next) {};
    template <typename ...Args>
    Node(KEmplace__ const& aEmpl, Args&&... val) : element(std::forward<Args>(val)...), next(nullptr), prev(nullptr) {}
};


template <typename Type> 
class Iterator 
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

    bool operator == (const Iterator& lhs) const;
    bool operator != (const Iterator& lhs) const;

    Iterator operator ++ ();
    Iterator operator -- ();

    Type& operator * ();

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
}

using namespace std;

//-------------------------------------------------------------------------------------------------
template <typename Type>
Iterator<Type>::Iterator(Node<Type>* ptr) : date(ptr) {}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Iterator<Type>::Iterator(const Iterator& iter) : Iterator(iter.date) {}
//-------------------------------------------------------------------------------------------------
template <typename Type>
bool Iterator<Type>::operator == (const Iterator& lhs) const 
{
    return (date == lhs.date);
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
bool Iterator<Type>::operator != (const Iterator& lhs) const 
{
    return (date != lhs.date);
}
//-------------------------------------------------------------------------------------------------
template <typename Type> Iterator<Type> Iterator<Type>::operator ++ () 
{
    date = date->next;
    return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type> Iterator<Type> Iterator<Type>::operator -- () 
{
    date = date->prev;
    return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type> Type& Iterator<Type>::operator * () 
{
    return date->element;
}


template <typename Type>
class Queue 
{
public:
    using iterator = Iterator<Type>;
    using const_iterator = Iterator<const Type>;
    using reverse_iterator = std::reverse_iterator<Iterator<Type>>;
    using const_reverse_iterator = std::reverse_iterator<Iterator<const Type>>;

public:
    Queue();
    Queue(const Queue& deq);
    Queue(Queue&& deq) noexcept;
    Queue(std::initializer_list<Type> list);
    Queue& operator = (const Queue& deq);
    Queue& operator = (Queue&& deq);
    ~Queue();

    Type& front();
    const Type& front() const;

    Type& back();
    const Type& back() const;

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail->next); }

    reverse_iterator rbegin() { return std::make_reverse_iterator(this->end()); }
    reverse_iterator rend() { return std::make_reverse_iterator(this->begin()); }
    
    bool empty() const;
    size_t size() const;
  
    void push_back(const Type& tp);

    template <typename ... Args>
    void emplace_back(Args&& ...val);

    void pop_front();

    void clear() noexcept;

    friend ostream& operator << (ostream& os, Queue<Type>& queue){ for(auto x : queue){ os << x << " ";} return os;}
private:
    size_t count{};
    Node<Type>* head;
    Node<Type>* tail;
};

template <typename Type>
size_t Queue<Type>::size() const
{
    return count;
}

template <typename Type>
bool Queue<Type>::empty() const
{
    return head == nullptr;
}

//Default  constructor 
template <typename Type>
Queue<Type>::Queue() : count(0), head(nullptr), tail(nullptr) {}

//Default destructor
template <typename Type>
Queue<Type>::~Queue()
{
    clear();
}

//Copy constructor
template <typename Type>
Queue<Type>::Queue(const Queue& deq) : count(deq.count), head(nullptr), tail(nullptr)
{
    for(const Node<Type>* p = deq.head; p != nullptr; p = p->next)
    {
        Node<Type>* p_new = new Node<Type>(KNoEmplace__(), p->element);
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
Queue<Type>::Queue(Queue&& deq) noexcept : count(deq.count), head(deq.head), tail(deq.tail)
{
    deq.count = 0;
    deq.head = nullptr;
    deq.tail = nullptr;
}

template<typename Type>
inline Queue<Type>::Queue(std::initializer_list<Type> list) : head(nullptr), tail(nullptr)
{
    for(Type x : list)
    {
        push_back(x);
        count++;
    }
}

//Copy operator ==
template <typename Type>
Queue<Type>& Queue<Type>::operator = (const Queue& deq)
{
    if(this == &deq)
    {
        return *this;
    }
    Queue tmp(deq);
    std::swap(count, tmp.count);
    std::swap(head, tmp.head);
    std::swap(tail, tmp.tail);
    return *this;
}

//Move operator ==
template <typename Type>
Queue<Type>& Queue<Type>::operator = (Queue&& deq)
{
    if(this == &deq)
    {
        return *this;
    }
    clear();
    std::swap(count, deq.count);
    std::swap(head, deq.head);
    std::swap(tail, deq.tail);
    return *this;
}

template <typename Type>
Type& Queue<Type>::front()
{
    if(empty())
    {
        throw std::out_of_range("ERROR : front is not allowed : queue is empty ");
    }
    return head->element;
}

template <typename Type>
const Type& Queue<Type>::front() const
{
    if(empty())
    {
        throw std::out_of_range("ERROR : front is not allowed : queue is empty ");
    }
    return head->element;
}

template <typename Type>
void Queue<Type>::push_back(const Type& tp)
{
    Node<Type>* p_new = new Node<Type>(KNoEmplace__(), tp);
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
Type& Queue<Type>::back()
{
    if(empty())
    {
        throw std::out_of_range("ERROR : back is not allowed : queue is empty");
    }
    return tail->element;
}

template <typename Type>
const Type& Queue<Type>::back() const
{
    if(empty())
    {
        throw std::out_of_range("ERROR : back is not allowed : queue is empty");
    }
    return tail->element;
}

template <typename Type>
void Queue<Type>::pop_front()
{
    if(empty())
    {
        throw std::out_of_range("ERROR : pop_front is not allowed : queue is empty");
    }
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
void Queue<Type>::clear() noexcept
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename Type>
template<typename ...Args>
inline void Queue<Type>::emplace_back(Args && ...val)
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

struct KTest
{
    KTest() {}
    KTest(int _a, double _b, long long _c): a(_a), b(_b), c(_c) {}
    friend ostream& operator << (ostream& os, KTest const& tst)
    { 
        os << "{" << tst.a << " " << tst.b << " " << tst.c << "}";
        return os;
    }

    int a;
    double b;
    long long c;
};

int main()
{
    Queue<int> qt1;
    qt1.push_back(10); qt1.push_back(12);
    Queue<int> qt2(qt1); qt2.push_back(30);
    cout << "qt1 = " << qt1 << ";  qt2 = " << qt2 << endl;

    Queue<int> xl = {10, 11, 12};
    xl.emplace_back(45);
    cout << xl << endl;

    auto it = xl.begin();
    cout << *(++it) << endl; cout << endl;
    xl.front() = 999999;
    for(auto it : xl){ cout << it << endl;}

    Queue<KTest> xTst = {KTest(1,1,1), KTest(2,2,2)};
    xTst.emplace_back(2, 3.14, 2222222);
    xTst.emplace_back();
    int k = 33;
    xTst.emplace_back(k, 6.28, 5555555);
    cout << xTst << endl;

    const Queue<int> qt4 = {1, 2, 3, 4};
    cout << qt4.front() << endl;
}