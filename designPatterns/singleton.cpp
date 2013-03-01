#include <pthread.h>
#include <stdexcept>
class Locker
{
    public:
        Locker(pthread_mutex_t &lock)
            :m_mutex(lock)
        {
            if(pthread_mutex_lock(&m_mutex)!=0)
		{
		throw std::runtime_error("Error locking mutex");
		}
        }
        ~Locker()
        {
		if( pthread_mutex_unlock(&m_mutex)!=0)
		{
		throw std::runtime_error("Error unlocking mutex");
		}
        }
    private:
        pthread_mutex_t&    m_mutex;
	Locker(Locker& l);
	Locker& operator=(Locker & l);
};

class MySingleton
{
public:
    static MySingleton& getInstance();

private:
    MySingleton& operator=( MySingleton const& s);
    MySingleton( MySingleton const& s);
    ~MySingleton();
    MySingleton();

    static pthread_mutex_t m_mutex;
};

pthread_mutex_t MySingleton::m_mutex = PTHREAD_MUTEX_INITIALIZER; 




MySingleton& MySingleton::getInstance()
{
    Locker lock(m_mutex);
    static MySingleton instance;
    return instance;
}

MySingleton::MySingleton()
{
}
