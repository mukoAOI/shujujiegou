#include <iostream>
#include <fstream>
#include<list>
using namespace std;
class has{
public:
    has(int mo);
    ~has();
    bool haspush(int key);
    bool init(char * filename);
    int search(int key);
    void showsearch(int key);
    void showhastable();
private:
    int mod;
    list<int>* hastable;
};

has::has(int mo) {
    mod=mo;
    hastable=new list<int> [mo];
}

has::~has() {
    delete [] hastable;
}

bool has::haspush(int key) {
    int a =key%mod;
    hastable[a].push_front(key);
    return true;
}

int has::search(int key) {
    int a=key%mod;
    int num=1;
    list<int>::iterator it=hastable[a].begin();
    while(it!=hastable[a].end()&&*it!=key)
    {
        num++;
        ++it;
    }
    if (*it!=key)
        return 0;
    else
        return num;
}

bool has::init(char * filename) {
    ifstream fin(filename);
    if (!fin.is_open())
        return false;
    int a;
    fin>>a;
    int i,j;
    for (i=0;i<a;i++)
    {
        fin>>j;
        haspush(j);
    }
    fin.close();
    return true;
}

void has::showhastable() {
    int i;
    for (i=0;i<mod;i++)
    {
        cout<< i<< "      ";
        list<int>::iterator it=hastable[i].begin();
        while(it!=hastable[i].end())
        {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }
}

void has::showsearch(int key) {
    int c=search(key);
    if (c)
        cout<<key<<"在"<<key%mod<<"行第"<<c<<"个"<<endl;
    else
        cout<<key<<"不存在"<<endl;
}
int main ()
{
    has one(13);
    one.init("C:/Users/23785/Desktop/table.txt");
    cout<<"展示表："<<endl;
    one.showhastable();
    cout<<"查找84"<<endl;
    one.showsearch(84);
    cout<<"查找76"<<endl;
    one.showsearch(64);
    return 0;
}