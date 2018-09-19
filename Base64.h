/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Base64.h
 * Author: Thong_Laptop
 *
 * Created on September 19, 2018, 10:18 AM
 */
/*************************************************************************************************/
#ifndef BASE64_H
#define BASE64_H
/*************************************************************************************************/
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>
#include <string.h>
/*************************************************************************************************/
using namespace std;
/*************************************************************************************************/
class Base64 {
public:
    Base64();
    Base64(const Base64& orig);
    virtual ~Base64();
    
    string encode(char* data, int len);
    vector<char> decode(std::string &str);
private:
    
};
/*************************************************************************************************/
#endif /* BASE64_H */
/*************************************************************************************************/
