/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Object.h
 * Author: Thong_Laptop
 *
 * Created on September 19, 2018, 10:24 AM
 */
/*************************************************************************************************/
#ifndef OBJECT_H
#define OBJECT_H
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
#include "Base64.h"
/*************************************************************************************************/
class Object {
public:
    /*********************************************************************************************/
    Object();
    Object(const Object& orig);
    virtual ~Object();
    Object& operator=(const Object& other);
    /*********************************************************************************************/
    string name;
    string type;
    int size;
    void* data;
    /*********************************************************************************************/
    string convertToData();
    bool convertFromData(string& data, int &index);
    /*********************************************************************************************/
private:
    /*********************************************************************************************/
    bool checkData(string& input, int& index, string comp);
    bool findData(string& input, int& index, char data);
    /*********************************************************************************************/
    Base64 m_base64;
    /*********************************************************************************************/
public:
    /*********************************************************************************************/
    template <typename T> bool set(string name, T& data) {
        this->name = name;
        this->type = getType(data);
        if (this->type.empty()) {
            return false;
        }
        this->size = 1;
        this->data = (void*)(&data);
        return true;
    }
    /*********************************************************************************************/
    template <typename T, size_t N> bool set(string name, T(&data)[N]) {
        this->name = name;
        this->type = getType(data[0]);
        if (this->type.empty()) {
            return false;
        }
        this->size = N;
        cout << this->type << endl;
        if (this->type.compare("string") == 0) {
            this->data = (void*)data;
        }
        else if (this->type.compare("object") == 0) {
            this->data = (void*)data;
        }
        else {
            this->data = (void*)data;
        }
        return true;
    }
    /*********************************************************************************************/
    template <typename T> bool set(string name, T* p_data, int size) {
        this->name = name;
        this->type = getType(p_data[0]);
        if (this->type.empty()) {
            return false;
        }
        this->size = size;
        if (this->type.compare("string") == 0) {
            this->data = p_data;
        }
        else if (this->type.compare("object") == 0) {
            this->data = p_data;
        }
        else {
            this->data = p_data;
        }
        return true;
    }
    /*********************************************************************************************/
    template <typename T> string getType(T& data) {
        if (typeid(T) == typeid(char))
            return "char";
        else if (typeid(T) == typeid(unsigned char))
            return "char";
        else if (typeid(T) == typeid(short))
            return "short";
        else if (typeid(T) == typeid(unsigned short))
            return "short";
        else if (typeid(T) == typeid(int))
            return "int";
        else if (typeid(T) == typeid(unsigned int))
            return "int";
        else if (typeid(T) == typeid(long))
            return "long";
        else if (typeid(T) == typeid(unsigned long))
            return "long";
        else if (typeid(T) == typeid(float))
            return "float";
        else if (typeid(T) == typeid(double))
            return "double";
        else if (typeid(T) == typeid(string))
            return "string";
        else if (typeid(T) == typeid(Object))
            return "object";
        else
            return string();
    }
    /*********************************************************************************************/
};
/*************************************************************************************************/
#endif /* OBJECT_H */
/*************************************************************************************************/
