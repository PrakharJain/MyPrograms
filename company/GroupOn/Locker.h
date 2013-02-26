#ifndef LOCKER_H
#define LOCKER_H
#include <pthread.h>

class Locker
{
    public:
        Locker(pthread_mutex_t &lock)
            :m_mutex(lock)
        {
            pthread_mutex_lock(&m_mutex);
        }
        ~Locker()
        {
            pthread_mutex_unlock(&m_mutex);
        }
    private:
        pthread_mutex_t&    m_mutex;
};

#endif //LOCKER_H
