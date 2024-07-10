#pragma once
////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdint>

#include <memory>
#include <any>
#include <vector>
#include <map>
#include <stack>
#include <array>
#include <string>

typedef unsigned char  uchar;
class ICommandBase
{
public:
    virtual void SetParameter(const std::any& param) = 0;
    virtual void Exec() = 0;
};

//Notifications

template <class T>
class NotificationImpl
{
public:
    void Clear() throw()
    {
        m_array.clear();
    }
    void AddNotification(const std::shared_ptr<T>& p)
    {
        m_array.push_back(p);
    }
    void RemoveNotification(const std::shared_ptr<T>& p) throw()
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            if( (*iter).get() == p.get() ) {
                m_array.erase(iter);
                return ;
            }
        }
    }

protected:
    std::vector<std::shared_ptr<T>> m_array;
};

class IPropertyNotification
{
public:
    virtual void OnPropertyChanged(const std::string& str) = 0;
};

class ICommandNotification
{
public:
    virtual void OnCommandComplete(const std::string& str, bool bOK) = 0;
};

template <class T>
class Proxy_PropertyNotification : public NotificationImpl<IPropertyNotification>
{
public:
    void AddPropertyNotification(const std::shared_ptr<IPropertyNotification>& p)
    {
        AddNotification(p);
    }
    void RemovePropertyNotification(const std::shared_ptr<IPropertyNotification>& p) throw()
    {
        RemoveNotification(p);
    }
    void Fire_OnPropertyChanged(const std::string& str)
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            (*iter)->OnPropertyChanged(str);
        }
    }
};

template <class T>
class Proxy_CommandNotification : public NotificationImpl<ICommandNotification>
{
public:
    void AddCommandNotification(const std::shared_ptr<ICommandNotification>& p)
    {
        AddNotification(p);
    }
    void RemoveCommandNotification(const std::shared_ptr<ICommandNotification>& p) throw()
    {
        RemoveNotification(p);
    }
    void Fire_OnCommandComplete(const std::string& str, bool bOK)
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            (*iter)->OnCommandComplete(str, bOK);
        }
    }
};
//i
