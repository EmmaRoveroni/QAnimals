#ifndef MODEL_CONTENITORE_H
#define MODEL_CONTENITORE_H


template<class T>
class Contenitore{
    friend class iteratore;
private:
    class nodo{
    public:
        nodo(const T& animale = T(), nodo* p = 0, nodo* n = 0): info(animale),prec(p),succ(n){}
        T info;
        nodo* prec;
        nodo* succ;
    };
    nodo* primo, *ultimo;
    int totelementi;
public:
    Contenitore():primo(0),ultimo(0),totelementi(0){}
    class iteratore{
        friend class Contenitore;
    private:
        nodo* ptr;
    public:
        iteratore(nodo* p=0){ptr=p;}
        nodo* getptr() const{return ptr;}
        bool operator ==(const iteratore& it) const{return ptr == it.ptr;}
        bool operator !=(const iteratore& it) const{return ptr != it.ptr;}
        iteratore& operator ++()
        {
            if(ptr) ptr=ptr->succ;
            return *this;
        }
        iteratore& operator --(){
            if(ptr) ptr=ptr->prec;
            return *this;
        }
        iteratore operator ++(int)
        {
            iteratore temp=*this;
            if(ptr) ptr=ptr->succ;
            return temp;
        }
        iteratore operator--(int){
            iteratore temp=*this;
            if(ptr) ptr=ptr->prec;
            return temp;
        }
        nodo& operator *() const{ return *ptr;}
    };
    nodo& operator[](const iteratore& it) const{return *(it.ptr);}

    iteratore begin() const{
        iteratore temp;
        temp.ptr=primo;
        return temp;
    }
    iteratore end() const{
        iteratore temp;
        temp.ptr=0;
        return temp;
    }

    iteratore delete_node(nodo* temp){
        iteratore aux;
        if(temp){
               if(temp==primo){
                   primo=aux.ptr=primo->succ;
                   if(primo) primo->prec=0;
               }else if(temp==ultimo){
                   ultimo=ultimo->prec;
                   if(ultimo) ultimo->succ=0;
               }else{
                   temp->prec->succ=aux.ptr=temp->succ;
                   temp->succ->prec=temp->prec;
               }
               delete temp;
               totelementi--;
           }
        return aux;
    }

    iteratore pop(const iteratore& it){
        if(!isEmpty()) return delete_node(it.getptr());
        else return iteratore();
    }

    void drop(){
            while(!isEmpty()) pop_back();
    }
    ~Contenitore(){
        drop();
    }

    int size() const{return totelementi;}

    bool isEmpty() const{return totelementi<=0;}

    void push_back(const T& b){
        if(primo && ultimo){
            ultimo->succ=new nodo(b,ultimo,0);
            ultimo=ultimo->succ;
        }else primo=ultimo=new nodo(b,0,0);
        totelementi++;
    }
    void pop_back(){
        if(!isEmpty()){
            totelementi--;
            nodo* temp=ultimo;
            ultimo=ultimo->prec;
            if(ultimo) ultimo->succ=0;
            delete temp;
        }
    }
};

#endif // MODEL_CONTENITORE_H
