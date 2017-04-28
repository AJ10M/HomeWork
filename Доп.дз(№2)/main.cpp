#include <iostream>
#include <string>
using namespace std;

struct person
{
    string name;
    float time;
    person* next;
    person* last;
    person( string name, float time )
    {
      this->name = name;
      this->time = time;
      next = NULL;
      last = NULL;
    };
};

class que
{
private:
    person* head;
    person* find_( string n , person* x )
    {
       if (x == NULL)
         return NULL;
       if (x->name == n)
         return x;
       return (find_(n, x->next));
    };

    void del( person* n )
    {
        if (n->last == NULL)
        {
            n->next->last=NULL;
            head = n->next;
            delete n;
        }
        if (n->next == NULL)
        {
            n->last->next = 0;
            delete n;
        }
       n->last->next = n->next;
       n->next->last = n->last;
       delete n;
    };

    person* last( person* x )
    {
       if (x == NULL)
         return NULL;
       if (x->next)
         return (x->next);
       return x;
    };

public:

    void push( string name, float time )
    {
      person* n = last (head);
      if (n)
          n->next = new person (name, time);
      n->next->last = n;
    };

    void exit( string name )
    {
      del(find_(name , head ));
    };

    person* get()
    {
       person* n = head;
       head->next->last = NULL;
       head = head->next;
       return n;
    };

    ~que()
    {
      while (head)
        del(head);
    };
};

int main()
{
    que Q;
    Q.push("A.Ibragimov", 10.00);
    Q.push("O.Popova", 12.30);
    Q.push("J.Renovich", 15.00);
    Q.push("A.Lugovin", 18.30);
    Q.exit("J.Renovich");
    for (;;)
    {
      person* x = Q.get();
      if (x) break;
      cout<<x->name<<' '<<x->time<<endl;
    };
    return 0;
}
