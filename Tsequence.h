#ifndef SEQUENCE
#define SEQUENCE
#include <assert.h>
namespace assignment04
{
	template <class T> class sequence
	{
    public:
        // TYPEDEFS and MEMBER SP2020
        typedef T value_type;
        typedef size_t size_type;
        static const size_type CAPACITY = 10;
        // CONSTRUCTOR
        sequence();
        // MODIFICATION MEMBER FUNCTIONS
        void start();
        void end();
        void advance();
        void move_back();
        void add(const value_type& entry);
        void remove_current();
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const;
        bool is_item() const;
        value_type current() const;

    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };

    //Needs to be in .h because it does not know the type at compile time
    //Needs it here so that it knows what to build, all in one module being compiled
    //Only goes into header files, if initialized in a cpp it wont be able to find it!!!

    template <class T> 
    sequence<T>::sequence() 
        : used(0), current_index(0) 
    { }

    template<class T> 
    void sequence<T>::start() 
    { 
        current_index = 0; 
    }

    template<class T>
    void sequence <T>::end()
    {
        current_index = (used > 0) ? used - 1 : 0;
    }

    template<class T> 
    void sequence <T>::advance()
    {
        assert(is_item());
        ++current_index;
    }

    template<class T> 
    void sequence <T>::move_back()
    {
        assert(is_item());
        if (current_index == 0)
            current_index = used;
        else
            --current_index;
    }

    template <class T> 
    void sequence<T>::add(const value_type& entry)
    {
        assert(size() < CAPACITY);

        size_type i;

        if (!is_item())
        {
            if (used > 0)
                for (i = used; i >= 1; --i)
                    data[i] = data[i - 1];
            data[0] = entry;
            current_index = 0;
        }
        else
        {
            ++current_index;
            for (i = used; i > current_index; --i)
                data[i] = data[i - 1];
            data[current_index] = entry;
        }
        ++used;
    }

    template <class T>
    void sequence<T>::remove_current()
    {
        assert(is_item());

        size_type i;

        for (i = current_index + 1; i < used; ++i)
            data[i - 1] = data[i];
        --used;
    }

    template <class T>
    typename sequence<T>::size_type sequence<T>::size() const
    { 
        return used;
    }

    template <class T>
    bool sequence<T>::is_item() const 
    { 
        return (current_index < used); 
    }

    template <class T>
    typename sequence<T>::value_type sequence<T>::current() const
    {
        assert(is_item());

        return data[current_index];
    }
}
#endif
