#include<iostream>
using namespace std;


class Artist{
    public:
        string fname,lname;
        string imageURL;
        Artist(string first_name,string last_name,string imageURL_given){
            fname=first_name;
            lname=last_name;
            imageURL=imageURL_given;
        }     
};

class Book{
    public:
        string authorName;
        string bookName;
        string imageURL;
        Book(string bookName_given, string authorName_given,string imageURL_given){
            authorName=authorName_given;
            bookName=bookName_given;
            imageURL=imageURL_given;
        }
};

class IResource{
    public:
        virtual string title()=0;
        virtual string image()=0;
};

class ArtistResource:public IResource{
    public:
        Artist* artist;
        ArtistResource(Artist* artist_given){
            artist=artist_given;
        }
        string title(){
            return artist->fname+" "+artist->lname;
        }
        string image(){
            return artist->imageURL;
        }
};

class BookResource:public IResource{
    public:
        Book* book;
        BookResource(Book* book_given){
            book=book_given;
        }
        string title(){
            return book->bookName+" "+book->authorName;
        }
        string image(){
            return book->imageURL;
        }
};

class View{
    public:
        IResource* resource;
        View(IResource* resource_given){
            resource=resource_given;
        }
        virtual void show()=0;
};

class LongFormView:public View{
    public:
        LongFormView(IResource* resourcegiven):View(resourcegiven){
        }
        void show(){
            cout<<"long form view of "<<resource->title()<<" "<<resource->image()<<endl;
        }
};

class ShortFormView:public View{
    public:
        ShortFormView(IResource* resourcegiven):View(resourcegiven){
        }
        void show(){
            cout<<"short form view of "<<resource->title()<<" "<<resource->image()<<endl;
        }
};

int main(){
    Artist* taylor=new Artist("taylor","swift","image1");
    Book* shout=new Book("shoutBook","memelee","image2");

    ArtistResource* ar=new ArtistResource(taylor);
    BookResource* br=new BookResource(shout);

    LongFormView* lfv=new LongFormView(ar);
    ShortFormView* sfv=new ShortFormView(br);

    lfv->show();
    sfv->show();
    return 0;
}
