#include "chord.h"
#include "finger.h"
#include "node.h"
using namespace std;

Node::Node(ll identifier, pair<ll, string> successor,
		pair<ll, string> predecessor) {

	this->identifier = identifier;
	this->successor = successor;
	this->predecessor = predecessor;
	this->finger_table.resize(M+1);

	for (int k = 1; k <= M; k++) {
		finger_table[k].start = (identifier + (1 << (k - 1))) % TOTAL_NODES;
	}

	for (int k = 1; k < M; k++) {
		finger_table[k].interval = make_pair(finger_table[k].start,
				finger_table[k + 1].start);
	}

	finger_table[M].interval = make_pair(finger_table[M].start,
			(finger_table[1].start - 1 + TOTAL_NODES) % TOTAL_NODES);
}

vector<Finger>& Node::getFingerTable() {
	return finger_table;
}

void Node::setFingerTable(vector<Finger>& fingerTable) {
	finger_table = fingerTable;
}

ll Node::getIdentifier() {
	return identifier;
}

void Node::setIdentifier(ll identifier) {
	this->identifier = identifier;
}

pair<ll, string>& Node::getPredecessor() {
	return predecessor;
}

void Node::setPredecessor(pair<ll, string>& predecessor) {
	this->predecessor = predecessor;
}

pair<ll, string>& Node::getSuccessor() {
	return successor;
}

void Node::setSuccessor(pair<ll, string>& successor) {
	this->successor = successor;
}

void Node::print_fingers() {

	for (int k = 1; k <= M; k++) {
		cout << "[" << finger_table[k].interval.first << ", "
				<< finger_table[k].interval.second << ")";

	}

}

