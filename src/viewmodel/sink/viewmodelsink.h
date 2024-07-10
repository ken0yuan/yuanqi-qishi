#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H
#include "../../common/base.h"
class viewmodel;
class viewmodelSink:public IPropertyNotification
{
public:
    viewmodelSink(viewmodel* p) throw();
    virtual void OnPropertyChanged(const std::string &str);
private:
    viewmodel* pvm;
};
#endif