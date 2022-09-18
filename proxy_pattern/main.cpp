#include<iostream>
#include<string>
using namespace std;

class IBookParser{
    public:
        virtual int getNumberOfPages()=0;
};

class BookParser:public IBookParser{
    public:
        string book;
        BookParser(string book_given){
            book=book_given;
            //a very expensive computation here
            cout<<"Very expensive computation in constructor\n";
        }
        int getNumberOfPages(){
            cout<<"inside getNumberOfPages method\n";
            return book.size();
        }
};

class LazyBookParserProxy:public IBookParser{
    private:
        BookParser* bookparser=NULL;
        string book;
    public:
        LazyBookParserProxy(string book_given){
            book=book_given;
        }
        int getNumberOfPages(){
            cout<<"inside getNumberOfPages method\n";
            if(bookparser==NULL){
                bookparser=new BookParser(book);
            }
            return book.size();
        }
};

//client code
int main(){
    string horrorStoryBook="BOO!!";
    //with normal bookparser we had to do expensive computation while creating object even if we are not sure whether we will need bookparser's methods
    BookParser* bp=new BookParser(horrorStoryBook);
    int sizeOfBook=bp->getNumberOfPages();
    cout<<sizeOfBook<<endl;

    //with proxy we can delay that expensive computation till we use bookparsers's methods
    LazyBookParserProxy* lpb=new LazyBookParserProxy(horrorStoryBook);
    sizeOfBook=lpb->getNumberOfPages();
    cout<<sizeOfBook<<endl;
}