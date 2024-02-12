#ifndef DICT_LIST_HPP
#define DICT_LIST_HPP

#include <iostream>

template <class T>
class DictionaryList
{
public:
    DictionaryList() :
        head_(nullptr)
    {}

    DictionaryList(DictionaryList&& right) :
        head_(right.head_)
    {
        right.head_ = nullptr;
    }

    DictionaryList& operator=(DictionaryList&& right)
    {
        if (this != &right)
        {
            head_ = right.head_;
            right.head_ = nullptr;
        }
        return *this;
    }

    ~DictionaryList()
    {
        while (head_)
        {
            remove(head_->data);
        }
    }

    bool insert(const T& newData)
    {
        if (!head_)
        {
            head_ = new Node(newData);
            return true;
        }

        if (head_->data > newData) 
        {
            Node* temp = new Node(newData);
            temp->next = head_;
            head_ = temp;
            return true;
        }

        Node* cur = head_;
        while (cur->next && cur->next->data < newData)
        {
            cur = cur->next;
        }
        
        if (cur->data < newData)
        {
            Node* temp = new Node(newData);
            temp->next = cur->next;
            cur->next = temp;
            return true;
        }
            
        return false;
    }

    bool remove(const T& oddData)
    {
        if (!head_)
        {
            return false;
        }
        if (head_->data == oddData)
        {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            return true;
        }
        Node* cur = head_;
        while (cur->next)
        {
            if (cur->next->data == oddData)    
            {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return true;   
            }
            cur = cur->next;
        }
        
        return false;
    }

    bool search(const T& searchData) const
    {
        Node* cur = head_;
        while (cur)
        {
            if (cur->data == searchData)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void merge(DictionaryList& right)
    {
        Node* thisCur = head_;
        bool needToDeleteFromRight = false;
        while (right.head_)
        {
            if (!head_)
            {
                Node* temp = new Node(right.head_->data);
                head_ = temp;
                thisCur = head_;
                needToDeleteFromRight = true;
            }
            else if (head_->data > right.head_->data)
            {
                Node* temp = new Node(right.head_->data);
                temp->next = head_;
                head_ = temp;
                thisCur = head_;
                needToDeleteFromRight = true;
            }
            
            else if (thisCur->data < right.head_->data)
            {
                if (!thisCur->next || thisCur->next->data > right.head_->data)
                {
                    Node* temp = new Node(right.head_->data);
                    temp->next = thisCur->next;
                    thisCur->next = temp;
                    needToDeleteFromRight = true;
                }
                else 
                {
                    thisCur = thisCur->next;
                }
            }
            else if (thisCur->data == right.head_->data)
            {
                needToDeleteFromRight = true;
            }
            else if (thisCur->data > right.head_->data)
            {
                right.head_ = right.head_->next;
            }
            
            if (needToDeleteFromRight)
            {
                Node* deleted = right.head_;
                right.head_ = right.head_->next;
                delete deleted;
                needToDeleteFromRight = false;
            }
        }
    }

    void deleteWords(const DictionaryList& right)
    {
        Node* rightCur = right.head_;
        Node* thisCur = head_;
        while(thisCur && rightCur)
        {
            if (head_->data == rightCur->data)
            {
                Node* temp = head_;
                head_ = head_->next;
                thisCur = head_;
                delete temp;
            }
            else if (thisCur->data > rightCur->data)
            {
                rightCur = rightCur->next;
            }
            else
            {
                if (thisCur->next)
                {
                    if (thisCur->next->data == rightCur->data)
                    {
                        Node* temp = thisCur->next;
                        thisCur->next = thisCur->next->next;
                        delete temp;
                    }
                    else if (thisCur->next->data > rightCur->data)
                    {
                        rightCur = rightCur->next;
                    }
                    else
                    {
                        thisCur = thisCur->next;
                    }
                }
                else
                {
                    thisCur = thisCur->next;
                }
            }
        }
    }

    friend DictionaryList getIntersection(const DictionaryList& left, const DictionaryList& right)
    {
        DictionaryList<T> result;
        Node* leftCur = left.head_;
        Node* rightCur = right.head_;
        Node* resultCur = result.head_;
        while (leftCur && rightCur)
        {
            if (leftCur->data == rightCur->data)
            {
                Node* temp = new Node(leftCur->data);
                if (!result.head_)
                {
                    result.head_ = temp;
                    resultCur = result.head_;
                }
                else
                {
                    resultCur->next = temp;
                    resultCur = resultCur->next;
                }
                leftCur = leftCur->next;
                rightCur = rightCur->next;
            }

            else if (leftCur->data < rightCur->data)
            {
                leftCur = leftCur->next;
            }
            else 
            {
                rightCur = rightCur->next;
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const DictionaryList& dictList)
    {
        Node* temp = dictList.head_;
        while (temp)
        {
            out << temp->data << ' ';
            temp = temp->next;
        }
        out << "DONE!";
        return out;
    }

    void clear()
    {
        this->~DictionaryList();
        head_ = nullptr;
    }

private:
    struct Node
    {
        Node(const T& newData) :
            data(newData),
            next(nullptr)
        {}
        T data;
        Node* next;
    };
    Node* head_;
};

#endif