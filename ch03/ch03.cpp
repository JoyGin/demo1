//
// Created by 王泽鑫 on 2024/2/21.
//

#include <iostream>
#include <cstring>

void q_3_1() {
    using std::cout;
    using std::endl;
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
}

void q_3_2_getLine() {
    std::string str;
    while (std::getline(std::cin, str)) {
        std::cout << str << std::endl;
    }
}

void q_3_2_getWord() {
    std::string word;
    while (std::cin >> word) {
        std::cout << word << std::endl;
    }
}

void q_3_4_getBigger() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    if (str1 == str2) {
        std::cout << "The two strings are equal." << std::endl;
        return;
    } else if (str1 > str2) {
        std::cout << str1 << std::endl;
    } else {
        std::cout << str2 << std::endl;
    }
}

void q_3_4_getLonger() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    if (str1.size() == str2.size()) {
        std::cout << "The two strings are equal." << std::endl;
        return;
    } else if (str1.size() > str2.size()) {
        std::cout << str1 << std::endl;
    } else {
        std::cout << str2 << std::endl;
    }
}

void q_3_5_cat() {
    std::string result;
    std::string tmp;
    while (std::cin >> tmp) {
        result += tmp;
    }
    std::cout << result << std::endl;
}

void q_3_5_catWithBlank() {
    std::string result;
    std::string tmp;
    while (std::cin >> tmp) {
        result = result + tmp + " ";
    }
    std::cout << result << std::endl;
}

void q_3_6() {
    std::string s = "Hello, World!";
    for (auto &c: s) {
        if (isalpha(c)) {
            c = 'X';
        }
    }
    std::cout << s << std::endl;
}

void q_3_7() {
    std::string s = "Hello, World!";
    for (char c: s) {
        if (isalpha(c)) {
            c = 'X';
        }
    }
    std::cout << s << std::endl;
}

void q_3_8_while() {
    std::string s = "Hello, World!";
    std::string::size_type index = 0;
    while (index < s.size()) {
        if (isalpha(s[index])) {
            s[index] = 'X';
        }
        index++;
    }
    std::cout << s << std::endl;
}

void q_3_8_tradition_for() {
    std::string s = "Hello, World!";
    for (decltype(s.size()) index = 0; index < s.size(); index++) {
        if (isalpha(s[index])) {
            s[index] = 'X';
        }
    }
    std::cout << s << std::endl;
}

void q_3_10() {
    std::string s = "Hello, World!";
    std::string result;
    for (auto c: s) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    std::cout << result << std::endl;
}

void q_3_16() {
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{10};     // size:1,  value:10
    vector<int> v5{10, 42}; // size:2,  value:10, 42
    vector<string> v6{10};  // size:10, value:""
    vector<string> v7{10, "hi"};  // size:10, value:"hi"

    cout << "v1 size :" << v1.size() << endl;
    cout << "v1 content :";
    for (auto i: v1) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v2 size :" << v2.size() << endl;
    cout << "v2 content :";
    for (auto i: v2) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v3 size :" << v3.size() << endl;
    cout << "v3 content :";
    for (auto i: v3) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v4 size :" << v4.size() << endl;
    cout << "v4 content :";
    for (auto i: v4) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v5 size :" << v5.size() << endl;
    cout << "v5 content :";
    for (auto i: v5) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v6 size :" << v6.size() << endl;
    cout << "v6 content :";
    for (auto i: v6) {
        cout << " " << i;
    }
    cout << endl;
    cout << "v7 size :" << v7.size() << endl;
    cout << "v7 content :";
    for (auto i: v7) {
        cout << " " << i;
    }
    cout << endl;
}

void q_3_17() {
    std::vector<std::string> sv;
    std::string s;
    while (std::cin >> s) {
        sv.push_back(s);
    }
    for (auto &s: sv) {
        for (auto &c: s) {
            c = toupper(c);
        }
    }
    for (auto s: sv) {
        std::cout << s << std::endl;
    }
}

void q_3_20() {
//    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> neighRes;
    for (decltype(iv.size()) index = 0; index < iv.size() - 1; index++) {
        int sum = iv[index] + iv[index + 1];
        neighRes.push_back(sum);
    }

    std::vector<int> foldPlusRes;
    for (decltype(iv.size()) index = 0; index < iv.size() / 2; index++) {
        int sum = iv[index] + iv[iv.size() - 1 - index];
        neighRes.push_back(sum);
    }
    if (iv.size() % 2 == 1) {
        neighRes.push_back(iv[iv.size() / 2]);
    }

    for (auto i: neighRes) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i: foldPlusRes) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void q_3_20_answer() {
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;
    vector<int> ivec;
    int i;
    while (cin >> i) {
        ivec.push_back(i);
    }

    for (int i = 0; i < ivec.size() - 1; ++i) {
        cout << ivec[i] + ivec[i + 1] << endl;
    }

    //---------------------------------
    cout << "---------------------------------" << endl;

    int m = 0;
    int n = ivec.size() - 1;
    while (m < n) {
        cout << ivec[m] + ivec[n] << endl;
        ++m;
        --n;
    }
}

void check_and_print(std::vector<int> v) {
    std::cout << "size: " << v.size() << ", content: [";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << (it == v.cend() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
}

void check_and_print(std::vector<std::string> v) {
    std::cout << "size: " << v.size() << " content [";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << (it == v.cend() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
}

void q_3_21() {
    using std::vector;
    using std::string;

    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    check_and_print(v1);
    check_and_print(v2);
    check_and_print(v3);
    check_and_print(v4);
    check_and_print(v5);
    check_and_print(v6);
    check_and_print(v7);
}

void q_3_23() {
    std::vector<int> v(10, 6);
    for (auto it = v.begin(); it != v.end(); it++) {
        *it *= 2;
    }
    for (auto it = v.cbegin(); it != v.cend(); it++) {
        std::cout << *it << " ";
    }
}

void q_3_24() {
    std::vector<int> v;
    int n = 0;
    while (std::cin >> n) {
        v.push_back(n);
    }

    for (auto it = v.cbegin(); it != v.cend() - 1; ++it) {
        std::cout << *it + *(it + 1) << std::endl;
    }

    //---------------------------------
    std::cout << "---------------------------------" << std::endl;

    auto begin = v.begin();
    auto end = v.cend() - 1;
    while (begin < end) {
        std::cout << *begin + *end << std::endl;
        begin++;
        end--;
    }
}

/**
 * 3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。
 */
void q_3_25() {
    std::vector<unsigned int> scores(11, 0);
    unsigned int grade = 0;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++(*(scores.begin() + grade / 10));
        }
    }
    for (auto i: scores) {
        std::cout << i << std::endl;
    }
}

/**
 * 练习3.31：编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
 */
void q_3_31() {
    int arr[10];
    for (auto i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    for (auto i: arr) {
        std::cout << i << std::endl;
    }
}

/**
 * 练习3.32：将上一题刚刚创建的数组拷贝给另外一个数组。利用vector重写程序，实现类似的功能。
 */
void q_3_32() {
    int arr1[10];
    for (auto i = 0; i < 10; i++) {
        arr1[i] = i;
    }
    int arr2[10];
    for (auto i = 0; i < 10; i++) {
        arr2[i] = arr1[i];
    }
    for (auto i: arr2) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    std::vector<int> v1(10);
    for (auto i = 0; i < 10; i++) {
        v1[i] = i;
    }
    std::vector<int> v2(10);
    for (auto i = 0; i < 10; i++) {
        v2[i] = v1[i];
    }
    for (auto i: v2) {
        std::cout << i << std::endl;
    }
}

/**
 * 练习3.35：编写一段程序，利用指针将数组中的元素置为0。
 */
void q_3_35() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto begin = std::begin(arr), end = std::end(arr); begin != end; begin++) {
        *begin = 0;
    }

    for (auto i: arr) {
        std::cout << i << std::endl;
    }
}

/**
 * 练习3.36：编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
 */
void q_3_36() {
    // 比较数组是否相同
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto begin1 = std::begin(arr1);
    auto end1 = std::end(arr1);
    auto begin2 = std::begin(arr2);
    auto end2 = std::end(arr2);

    // 长度是否一样
    if ((end1 - begin1) != (end2 - begin2)) {
        std::cout << "The two arrays are unequal" << std::endl;
    } else {
        // 长度一样，判断数组内容是否一样
        bool equal = true;
        for (; (begin1 != end1) && (begin2 != end2); begin1++, begin2++) {
            if (*begin1 != *begin2) {
                equal = false;
            }
        }
        if (equal) {
            std::cout << "The two arrays are equal" << std::endl;
        } else {
            std::cout << "The two arrays are unequal" << std::endl;
        }
    }

//    std::cout << "--------------------" << std::endl;

    // 比较两个 vector 是否相同
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (vec1 == vec2) {
        std::cout << "The two vectors are equal" << std::endl;
    } else {
        std::cout << "The two vectors are unequal" << std::endl;
    }
}

/**
 * 练习3.39：编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
 */
void q_3_39() {
    std::string str1 = "hello";
    std::string str2 = "world";

    if (str1 > str2) {
        std::cout << str1 << " bigger than " << str2 << std::endl;
    } else if (str1 < str2) {
        std::cout << str1 << " smaller than " << str2 << std::endl;
    } else {
        std::cout << str1 << " equal to " << str2 << std::endl;
    }

    char cstr1[] = "chello";
    char cstr2[] = "cworld";

    if (std::strcmp(cstr1, cstr2) > 0) {
        std::cout << cstr1 << " bigger than " << cstr2 << std::endl;
    } else if (std::strcmp(cstr1, cstr2) < 0) {
        std::cout << cstr1 << " smaller than " << cstr2 << std::endl;
    } else {
        std::cout << cstr1 << " equal to " << cstr2 << std::endl;
    }
}

/**
 * 练习3.40：编写一段程序，定义两个字符数组并用字符串字面值初始化
 * 它们；接着再定义一个字符数组存放前两个数组连接后的结果。使用
 * strcpy和strcat把前两个数组的内容拷贝到第三个数组中。
 */
void q_3_40() {
    char cstr1[] = "hello";
    char cstr2[] = "world";

    // 复制拼接
    char catStr[11];
    strcat(catStr, cstr1);
    strcat(catStr, cstr2);

    std::cout << catStr << std::endl;
}

/**
 * 练习3.41：编写一段程序，用整型数组初始化一个vector对象。
 */
void q_3_41() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> v(std::begin(arr), std::end(arr));

    for (auto i: v) {
        std::cout << i << std::endl;
    }
}

/**
 * 练习3.42：编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
 */
void q_3_42() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[9];
    for (decltype(v.size()) i = 0; i < v.size(); ++i) {
        arr[i] = v[i];
    }

    for (auto i: arr) {
        std::cout << i << std::endl;
    }
}

/**
 * todo:try again
 * 练习3.43：编写3个不同版本的程序，令其均能输出ia的元素。版本1使
 * 用范围for语句管理迭代过程；版本2和版本3都使用普通的for语句，其
 * 中版本2要求用下标运算符，版本3要求用指针。此外，在所有3个版本
 * 的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或
 * decltype关键字。
 */
void q_3_43() {
    int ia[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };

    // 范围 for
    for (int (&row)[4] : ia) {
        for (int i : row) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // 传统 for，下标
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            std::cout << ia[i][j] << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // 传统 for，指针
    for (int (*i)[4] = ia; i != ia + 3; i++) {
        for (int *j = *i; j != *i + 4; j++) {
            std::cout << *j << std::endl;
        }
    }
}

/**
 * todo:try again
 * 练习3.44：改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
 */
void q_3_44() {
    using int_array = int [4];

    int ia[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };

    // range for
    for (int_array &row: ia) {
        for (int i: row) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // loop for
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            std::cout << ia[i][j] << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // pointer for
    for (int_array *i = ia; i < ia + 3; i++) {
        for (int* j = *i; j < *i + 4; j++) {
            std::cout << *j << std::endl;
        }
    }
}

/**
 * todo:try again
 * 练习3.45：再一次改写程序，这次使用auto关键字。
 */
void q_3_45() {
    int ia[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };

    // range for
    for (auto &row: ia) {
        for (int i: row) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // loop for
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            std::cout << ia[i][j] << std::endl;
        }
    }
    std::cout << "-----------------" << std::endl;

    // pointer for
    for (auto *i = ia; i < ia + 3; i++) {
        for (int* j = *i; j < *i + 4; j++) {
            std::cout << *j << std::endl;
        }
    }
}

void e_digital_to_xdigital() {
    std::string hexDic = "0123456789ABCDEF";
    std::string::size_type n;
    std::string result;
    while (std::cin >> n) {
        if (n < hexDic.size()) {
            result += hexDic[n];
        }
    }
    std::cout << result << std::endl;
}

void e_square() {
    std::vector v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i: v) {
        i *= i;
    }
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void e_grade() {
    std::vector<unsigned int> scores(11, 0);
    unsigned int grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            scores[grade / 10] += 1;
        }
    }
    for (auto i: scores) {
        std::cout << i << " ";
    }
}

int main() {
//    q_3_1();
//    q_3_2_getLine();
//    q_3_2_getWord();
//    q_3_3_getBigger();
//    q_3_3_getLonger();
//    q_3_5_cat();
//    q_3_5_catWithBlank();
//    q_3_6();
//    q_3_7();
//    q_3_8_while();
//    q_3_8_tradition_for();
//    q_3_10();
//    q_3_16();
//    q_3_17();
//    q_3_20();
//    q_3_20_answer();
//    q_3_21();
//    q_3_23();
//    q_3_24();
//    q_3_25();
//    q_3_31();
//    q_3_32();
//    q_3_35();
//    q_3_36();
//    q_3_39();
//    q_3_40();
//    q_3_41();
//    q_3_42();
//    q_3_43();
//    q_3_44();
    q_3_45();

//    e_digital_to_xdigital();
//    e_square();
//    e_grade();


    return 0;
}