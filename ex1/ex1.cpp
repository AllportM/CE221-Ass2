//// temporary main function to allow testing of Student class
//// this file should not be submitted as part of the assignment
//
//using namespace std;
//#include <iostream>
//#include <stdexcept>
//#include <iomanip>
//#include <list>
//#include "Student.h"
//
//class A
//{
//    public:
//        A(const string name)
//        {
//            this->name = name;
//        }
//
//        string getName() const
//        {
//            return name;
//        }
//    protected:
//        string name;
//};
//
//class B : public A
//{
//    public:
//        B(const string name, const float mark): A(name)
//        {
//            this-> mark = mark;
//        }
//
//        friend ostream &operator<<(ostream &str, const B &b);
//    protected:
//        float mark;
//
//};
//
//ostream &operator<<(ostream &str, const B &b)
//{
//    str << setfill(' ') << '|' << setw(20) << b.getName() << '|' << endl << '|' << b.mark << '|' << endl;
//    return str;
//}
//
//int main()
//{
////    Student s("Harry Potter", 12345);
////    s.changeName("Harriet Potter");
////    cout << "Name is " << s.getName() << endl;
////    cout << "Reg is " << s.getRegNo() << endl;
////    s.addMark("CE151", 99.5);
////    s.addMark("CE221", 5.5);
////    try
////    { cout << "Mark for CE151 is " << s.getMark("CE151") << endl;
////    }
////    catch (NoMarkException e)
////    { cout << "No mark for CE151" << endl;
////    }
////    try
////    { cout << "Mark for CE204 is " << s.getMark("CE204") << endl;
////    }
////    catch (NoMarkException e)
////    { cout << "No mark for CE204" << endl;
////    }
////    cout << s;
////    Student t("Terry Pratchet", 12350);
////    cout << "\n" << t;
////    cout << "\n" << (s < t);
//    B b(string("Henry"), 100.0);
//    cout << b;
//    list<B*> bs;
//    bs.push_front(new B(string("Henry"), 100.0));
//    bs.push_front(new B(string("Tierry"), 99.0));
//    bs.push_front(new B(string("Frank"), 75.0));
//    for (B *b: bs)
//    {
//        cout << *b << endl;
//    }
//}
