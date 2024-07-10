#include "viewmodelsink.h"
#include "../viewmodel.h"
viewmodelSink::viewmodelSink(viewmodel* p) throw():pvm(p){}
void viewmodelSink::OnPropertyChanged(const std::string &str)
{
    pvm->Fire_OnPropertyChanged(str);
}