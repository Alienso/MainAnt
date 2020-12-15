#include "./headers/Input.h"

Input::Input (QWidget *parent) : QFrame (parent)
{
    setMinimumSize(20,20);
    setMaximumSize(20,20);
    setAcceptDrops(true);
    setStyleSheet ("background-color: rgba(205, 221, 63, 1);");
    setLayout(new QGridLayout());
    previous = nullptr;
}

void Input::dropEvent(QDropEvent *event)
{
    QByteArray t = event->mimeData()->data("node_ptr");
    std::string s = t.toStdString();
    uintptr_t x = stoaddr(s);
    Output* ptr = reinterpret_cast<Output*>(x);

    if (!t.isEmpty ())
    {
        this->previous = ptr;
        //Pokazivac na covr ciji output povezujemo na ovaj input
        Node* parent = static_cast<Node*>(ptr->parent());
        //POkazivac na cvor ciji je ovo Input
        Node* node = static_cast<Node*>(this->parent());

        parent->addChildren(node);
        node->addParents(parent);

        setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
    }
    event->accept ();
}

//String to address - stoaddr
//Takes and String of ones and zeroes and returns
//a memory adress to what the string pointst to
uintptr_t Input::stoaddr(std::string s){

    uintptr_t x = 0;
    unsigned  size = sizeof(void*) * 8;
    unsigned long mask;
    unsigned  i = 0;
    for (mask = 1ul << (size-1); mask != 0; mask >>= 1){
        if (s[i] == '1'){
            x = x | mask;
        }
        i++;
    }
    return x;
}

void Input::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept ();
    setStyleSheet ("background-color: rgba(255, 0, 0, 0.5);");
}

void Input::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept ();
    setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
}

Output* Input::getPrevious()
{
    return this->previous;
}

void Input::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::RightButton){
        QPoint globalPos=this->mapToGlobal(event->pos());
        QMenu myMenu;
        myMenu.addAction("Delete");
        QAction *selectedItem=myMenu.exec(globalPos);
        if(selectedItem){
            if(selectedItem->toolTip()=="Delete"){
                this->previous = nullptr;
                setStyleSheet ("background-color: rgba(205, 221, 63, 1);");
            }
        }
    }
}
