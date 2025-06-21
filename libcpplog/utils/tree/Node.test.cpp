#include <libcpplog/utils/tree/Node.test.hpp>
#include <libcpplog/utils/tree/Node.hpp>

#include <array>
#include <cassert>
#include <iostream>
#include <ranges>
#include <source_location>
#include <span>
#include <string>

int main(int argc, char* arv[]) {

	cpplog::utils::tree::unit_test::NodeTest test;

	test.testGetId();

	test.testAddingChildNodesCopy();
	test.testAddingChildNodesMove();

	test.testIteratingRangeBased();
	test.testIteratingChildNodes();

	std::cout << "UT: utils::tree::Node passed." << std::endl;
	return 0;
}

namespace cpplog::utils::tree::unit_test {

	void NodeTest::testGetId() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetId()" << std::endl;

		using IntNode = Node<int>;

		IntNode node(3);

		assert(node.getId() == 3);
	}

	void NodeTest::testAddingChildNodesCopy() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testAddingChildNodesCopy()" << std::endl;

		using StrNode = Node<std::string>;

		StrNode node("Root");
		StrNode child("Child");

		node.add(child);

		assert(node.begin()->getId() == "Child");
	}

	void NodeTest::testAddingChildNodesMove() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testAddingChildNodesMove()" << std::endl;

		using StrNode = Node<std::string>;

		StrNode node("Root");
		StrNode child("Child");

		node.add(std::move(child));

		assert(node.begin()->getId() == "Child");
	}

	void NodeTest::testIteratingRangeBased() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testIteratingRangeBased()" << std::endl;

		using StrNode = Node<std::string>;

		std::array<std::string, 4> expected = { "Child1", "Child2", "Child3", "Child4" };

		StrNode root("Root");
		for (const auto& child : expected) {
			root.add(StrNode(child));
		}

		for (const auto& child : root) {
			child.getId();
		}

	}

	void NodeTest::testIteratingChildNodes() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testIteratingChildNodes()" << std::endl;

		using StrNode = Node<std::string>;

		std::array<std::string, 4> expected = { "Child1", "Child2", "Child3", "Child4" };

		StrNode root("Root");
		for (const auto& child : expected) {
			root.add(StrNode(child));
		}

		std::ranges::zip_view zip{ root.getChildNodes(), expected };

		for (const auto& [child, expected] : zip) {
			assert(child.getId() == expected);
		}

	}

}