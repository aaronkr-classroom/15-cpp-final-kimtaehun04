#ifndef GUARD_Handle_h
#define GUARD_Handle_h

// Minimal Handle template to manage polymorphic objects by value

template <class T>
class Handle {
public:
    Handle() : p(0) {}
    Handle(T* t) : p(t) {}
    Handle(const Handle& h) : p(h.p ? h.p->clone() : 0) {}
    Handle& operator=(const Handle& h) {
        if (&h != this) {
            delete p;
            p = h.p ? h.p->clone() : 0;
        }
        return *this;
    }
    ~Handle() { delete p; }

    T& operator*() const { return *p; }
    T* operator->() const { return p; }
    operator bool() const { return p != 0; }

private:
    T* p;
};

#endif
