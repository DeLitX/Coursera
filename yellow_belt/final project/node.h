#pragma once
#include"date.h"
#include<memory>
enum class LogicalOperation {
    Or,
    And
};
enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};
class Node {
public:
	virtual bool Evaluate(const Date& date,const string& event) = 0;
};
class EmptyNode :public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const string& event);
};
class DateComparisonNode :public Node {
public:
	DateComparisonNode(const Comparison& cmp,const Date& date);
    bool Evaluate(const Date& date, const string& event);
private :
    const Date date_;
    const Comparison cmp_;
};
class EventComparisonNode :public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value);
    bool Evaluate(const Date& date, const string& event);
private:
    const string event_;
    const Comparison cmp_;
};
class LogicalOperationNode :public Node {
public:
    LogicalOperationNode(const LogicalOperation& logicalOperation, shared_ptr<Node> left, shared_ptr<Node> right);
    bool Evaluate(const Date& date, const string& event);
private:
    LogicalOperation lOp_;
    shared_ptr<Node> left_, right_;
};