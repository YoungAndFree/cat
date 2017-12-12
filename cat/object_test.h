//
// Created by key on 2017/12/12.
//

#ifndef CAT_OBJECT_TEST_H
#define CAT_OBJECT_TEST_H

#include <iostream>
#include <thread>
#include "singleton.hpp"
#include <atomic>
#include <boost/thread.hpp>
#include "cloneable.hpp"

class person : public cat::cloneable
{
public:
    person(){}
    ~person(){}

    int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        person::age = age;
    }

    const std::string &getName() const
    {
        return name;
    }

    void setName(const std::string &name)
    {
        person::name = name;
    }

protected:
    bool copy(data_ptr d, const data_ptr &s) override
    {
        bool res = false;

        auto des = ptr_cast<person>(d);
        auto source = ptr_cast<person>(s);
        if (des && source)
        {
            des->age = source->age;
            des->name = source->name;

            res = true;
        }
        else
        {
            res = false;
        }
        return res;
    }

private:
    int             age;
    std::string     name;
};

class student : public person
{
public:
    student(){}
    ~student(){}

    const std::string &getSchoolName() const
    {
        return schoolName;
    }

    void setSchoolName(const std::string &schoolName)
    {
        student::schoolName = schoolName;
    }

protected:
    bool copy(data_ptr d, const data_ptr &s) override
    {
        bool res = person::copy(d, s);

        auto des = ptr_cast<student>(d);
        auto source = ptr_cast<student>(s);
        if (des && source)
        {
            des->schoolName = source->schoolName;
            res = true;
        }
        else
        {
            res = false;
        }
        return res;
    }

private:
    std::string schoolName;
};

class printAction
{
public:
    printAction(){}
    ~printAction(){}

    void println(std::weak_ptr<person> wk_person)
    {
        auto sp_person = wk_person.lock();
        if (sp_person)
        {
            if (auto sp_student = std::dynamic_pointer_cast<student>(sp_person))
            {
                std::cout << "***************************" << std::endl;
                std::cout << "name: " << sp_student->getName()
                          << "  age: " << sp_student->getAge()
                          << "  school:   " << sp_student->getSchoolName()
                          << std::endl;
                std::cout << "***************************" << std::endl;
            }
            else
            {
                std::cout << "***************************" << std::endl;
                std::cout << "name: " << sp_person->getName()
                          << "  age: " << sp_person->getAge()
                          << std::endl;
                std::cout << "***************************" << std::endl;
            }

        }
    }
};

void test()
{
    //std::unique_ptr<printAction> sp_print(new printAction);

    //std::shared_ptr<person> sp_person1(new person);
    //sp_person1->setAge(10);
    //sp_person1->setName("lucy");
    //sp_print->println(sp_person1);

    //std::shared_ptr<person> sp_person2 = sp_person1->clone<person>();
    //sp_person2->setAge(20);
    //sp_print->println(sp_person1);
    //sp_print->println(sp_person2);

    //std::shared_ptr<student> sp_student1(new student);
    //sp_student1->setAge(30);
    //sp_student1->setName("jack");
    //sp_student1->setSchoolName("aaaaaa");
    //std::shared_ptr<student> sp_student2 = sp_person1->clone<student>();
    //sp_student2->setAge(31);
    //sp_print->println(sp_student1);

    //std::shared_ptr<person> sp_person3 = sp_person1->clone<student>();
    //sp_print->println(sp_person3);
}
#endif //CAT_OBJECT_TEST_H
