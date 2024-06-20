#include "link_installer.h"

Link* LinkInstaller::install(Node *a, Node *b){
    Link* newLink = new Link(a, b);
    a->myLink_.push_back(newLink);
    b->myLink_.push_back(newLink);
    return newLink;
}