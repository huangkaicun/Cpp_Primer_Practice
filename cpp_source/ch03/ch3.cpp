//
// Created by cer
// chapter 3
// 字符串、向量和数组

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

// void basic_getline(){
//     string line;
//     while (getline(cin, line))
//         cout << line << endl;
// }
//q: cin 是什么？ cin 是istream对象，是一个类，有一个getline方法，getline方法的第一个参数是istream对象，第二个参数是string对象，返回值是istream对象
//q: 下面这个方法的输出是什么？
//a: 什么都没有，因为cin是istream对象，没有getline方法
void basic_getline(){
    string line;
    while (getline(cin, line)){
        if (!line.empty()){
            cout << line << endl;
        }
    }
}

// void basic_string(){
//     string s = "Test String.";
//     cout << "Size: " << s.size() << endl
//          << "Empty: " << s.empty() << endl
//          << "char at index 0:" << s[0] << endl;
//     for(string::size_type i=0; i<s.size(); i++){
//         cout << s[i];
//     }
//     cout << endl;
// }
//q:这个方法的输出是什么？
//a: 什么都没有，因为string对象没有size方法 
void basic_string(){
    string s = "Test String.";
    cout << "Size: " << s.size() << endl
         << "Empty: " << s.empty() << endl
         << "char at index 0:" << s[0] << endl;
    for(string::size_type i=0; i<s.size(); i++){
        cout << s[i];
    }
      
}

// void basic_vector(){
//     vector<int> v;
//     for (int i = 0; i != 10; i++){
//         v.push_back(i);
//     }
//     for (vector<int>::iterator iter = v.begin();
//          iter != v.end(); ++iter){
//         *iter = 0;
//     }
//     // 不能直接输出vector
// }
//a: 
void basic_vector(){
    vector<int> v;
    for (int i = 0; i != 10; i++){
        v.push_back(i);
        // cout << v[i] << endl;
    }
    cout << v.size() << endl;
    cout << v[7] << endl;
    for (vector<int>::iterator iter = v.begin();
            iter != v.end(); ++iter){
            *iter = 0;
            // cout << *iter << endl;
        }
}
//q: copilot voice 为什么不能用？
//a: 
// void basic_bieset(){
//     bitset<16> bitvec1(0xffff);
//     string bit_str = "1100";
//     bitset<32> bitvec2(bit_str); //从右到左读取字符串，只能是string对象，不能是字面值
//     bitset<16> bitvec3(bit_str, 0, 3); // 只要前三位
//     cout << bitvec1 << endl
//          << bitvec2 << endl
//          << bitvec3 << endl
//          << bitvec2.test(3) <<" " <<bitvec2.test(3) << endl
//          << bitvec2.to_ulong() << endl;
// }
/**
 * @brief A bitset object constructed from a string.
 * 
 * The string is read from right to left, and only the first 32 characters are used.
 * 
 */
void basic_bieset(){
    bitset<16> bitvec1(0xffff);
    string bit_str = "1100";
    bitset<32> bitvec2(bit_str);
    bitset<16> bitvec3(bit_str, 0, 3); // 只要前三位
    cout << bitvec1 << endl
         << bitvec2 << endl
         << bitvec3 << endl
         << bitvec2.test(3) <<" " <<bitvec2.test(3) << endl
         << bitvec2.to_ulong() << endl;
}

// void q_3_14(){
//     vector<int> v;
//     int i;
//     while (cin >> i){
//         v.push_back(i);
//     }
// }
void q_3_14(){
    vector<int> v;
    int i;
    while (cin >> i){
        v.push_back(i);
    }
    for (auto one : v){
        cout << one <<endl;
    }
}

// void q_3_17(){
//     vector<string> v;
//     string s;
//     while (cin >> s){
//         v.push_back(s);
//     }
//     for (auto &str : v)
//     {
//         for (auto &c : str)
//         {
//             c = toupper(c);
//         }
//     }
//     for (auto str : v){
//         cout << str << endl;
//     }
// }
//q: 这个方法的输出是什么？
//a: 
void q_3_17(){
    vector<string> v;
    string s;
    //q: 为什么这里不能用cin >> s
    //a: 因为cin >> s 会把空格作为分隔符，所以只能读取到第一个单词
    //q: cin>>s 是什么意思？
    //a: cin是istream对象，>>是istream对象的方法，第一个参数是istream对象，第二个参数是string对象，返回值是istream对象
    while (cin >> s){
        v.push_back(s);

    }
    //q: 这个auto &str是什么意思？str:v 是什么意思？
    //a: auto &str 是string对象的引用，str:v 是把v中的每一个元素赋值给str
    for (auto &str : v){
        //q: 为什么要用引用？
        //a: 因为这里要改变str的值，如果不用引用，str只是v中的一个副本，改变str的值不会改变v中的值
        for (auto &c : str){
            c = toupper(c);
        }
    }
    for (auto str : v){
        cout << str << endl;
    }
}
//q:这个方法的输出是什么？
//a: 1 2 3 4 5 6 7 8 9 10

// void q_3_23(){
//     vector<int> v(10, 1);
//     for (auto it=v.begin(); it!=v.end(); it++){
//         *it *= 2;
//     }
//     for (auto one : v){
//         cout << one <<endl;
//     }
// }
//q: 这个方法的输出是什么？
//a: 
//q: 为什么这个方法的输出是十个2？
//a: 
void q_3_23(){
    vector<int> v(10,1);
    for (auto it = v.begin(); it != v.end(); it++){
        //q: *it 是什么意思？
        //a: *it 是it指向的对象
        //q: 为什么要用*it，而不是it？
        //a: 因为it是一个迭代器，指向一个对象，*it是it指向的对象
        *it *= 2;

    }
    for (auto one : v){
        cout << one <<endl;
    }
}

void q_3_31(){
    int a[10];
    for (size_t i=0; i != 10; i++){
        a[i] = i;
    }
}

int main(){
//    basic_getline();
//    basic_string();
//    basic_vector();
//    basic_bieset();
//    q_3_14();
//    q_3_17();
    q_3_23();
}