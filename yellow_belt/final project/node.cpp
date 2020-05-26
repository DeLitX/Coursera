#include "node.h"
EmptyNode::EmptyNode(){
}
bool EmptyNode::Evaluate(const Date& date, const string& event) {
	return true;
}
DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date):cmp_(cmp),date_(date) {

}
bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
	switch (cmp_) {
	case Comparison::Less:
		return date_ > date;
	case Comparison::LessOrEqual:
		return date_ >= date;
	case Comparison::Equal:
		return date_ == date;
	case Comparison::NotEqual:
		return date_ != date;
	case Comparison::Greater:
		return date_ < date;
	case Comparison::GreaterOrEqual:
		return date_ <= date;
	}
}
EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& value):event_(value),cmp_(cmp) {

}
bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
	switch (cmp_) {
	case Comparison::Less:
		return event_ > event;
	case Comparison::LessOrEqual:
		return event_ >= event;
	case Comparison::Equal:
		return event_ == event;
	case Comparison::NotEqual:
		return event_ != event;
	case Comparison::Greater:
		return event_ < event;
	case Comparison::GreaterOrEqual:
		return event_ <= event;
	}
}
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logicalOperation, shared_ptr<Node> left, shared_ptr<Node> right):lOp_(logicalOperation),
left_(left),right_(right){

}
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
	if (lOp_ == LogicalOperation::And) {
		return left_->Evaluate(date, event) && right_->Evaluate(date, event);
	}
	return left_->Evaluate(date, event) || right_->Evaluate(date, event);
}