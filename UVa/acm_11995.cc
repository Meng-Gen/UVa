#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

struct PriorityQueueSimulator {
    PriorityQueueSimulator() : is_valid_(true) { }

    bool IsValid() const { return is_valid_; }

    void Push(int element) {
        if (is_valid_) {
            itself_.push(element);
        }
    }

    void Pop(int element) {
        if (is_valid_) {
            if (itself_.size() == 0 || itself_.top() != element) {
                is_valid_ = false;
            } else {
                itself_.pop();
            }
        }
    }

    std::priority_queue<int> itself_;
    bool is_valid_;
};

struct QueueSimulator {
    QueueSimulator() : is_valid_(true) { }

    bool IsValid() const { return is_valid_; }

    void Push(int element) {
        if (is_valid_) {
            itself_.push(element);
        }
    }

    void Pop(int element) {
        if (is_valid_) {
            if (itself_.size() == 0 || itself_.front() != element) {
                is_valid_ = false;
            } else {
                itself_.pop();
            }
        }
    }

    std::queue<int> itself_;
    bool is_valid_;
};

struct StackSimulator {
    StackSimulator() : is_valid_(true) { }
    
    bool IsValid() const { return is_valid_; }

    void Push(int element) {
        if (is_valid_) {
            itself_.push(element);
        }
    }

    void Pop(int element) {
        if (is_valid_) {
            if (itself_.size() == 0 || itself_.top() != element) {
                is_valid_ = false;
            } else {
                itself_.pop();
            }
        }
    }

    std::stack<int> itself_;
    bool is_valid_;
};

int main(int argc, char* argv[])
{
    int num_cmd;
    while (std::cin >> num_cmd)
    {
        PriorityQueueSimulator priority_queue_simulator;
        QueueSimulator queue_simulator;
        StackSimulator stack_simulator;

        int cmd_type, element;
        for (int i = 0; i < num_cmd; i++)
        {
            std::cin >> cmd_type >> element;
            if (cmd_type == 1)
            {
                priority_queue_simulator.Push(element);
                queue_simulator.Push(element);
                stack_simulator.Push(element);
            }
            else if (cmd_type == 2)
            {
                priority_queue_simulator.Pop(element);
                queue_simulator.Pop(element);
                stack_simulator.Pop(element);
            }
        }

        bool is_priority_queue = priority_queue_simulator.IsValid();
        bool is_queue = queue_simulator.IsValid();
        bool is_stack = stack_simulator.IsValid();

        if (is_priority_queue && !is_queue && !is_stack)
        {
            puts("priority queue");
        }
        else if (!is_priority_queue && is_queue && !is_stack)
        {
            puts("queue");
        }
        else if (!is_priority_queue && !is_queue && is_stack)
        {
            puts("stack");
        }
        else if (!is_priority_queue && !is_queue && !is_stack)
        {
            puts("impossible");
        }
        else
        {
            puts("not sure");
        }
    }
    
    return 0;
}